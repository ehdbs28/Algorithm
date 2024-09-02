#include<iostream>
#include<queue>

#define pii pair<int, int>

using namespace std;

int main(){
    int n;
    int map[3][3] = {};
    bool visited[3][3] = {};

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    queue<pii> q;
    q.emplace(0, 0);
    visited[0][0] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int nx = cx + map[cy][cx];
        if(nx < n &&!visited[cy][nx]){
            visited[cy][nx] = true;
            q.emplace(nx, cy);
        }

        int ny = cy + map[cy][cx];
        if(ny < n && !visited[ny][cx]){
            visited[ny][cx] = true;
            q.emplace(cx, ny);
        }
    }

    cout << (visited[n - 1][n - 1] ? "HaruHaru" : "Hing");
}
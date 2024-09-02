#include<iostream>

using namespace std;

char map[5][5] = {};
bool visited[5][5] = {};

int dist[2][4] = {
    { 1, -1, 0, 0 },
    { 0, 0, 1, -1 }
};

int r;
int c;
int k;

int DFS(int cx, int cy, int ck){
    if(cx == c - 1 && cy == 0){
        return ck == k;
    }

    visited[cy][cx] = true;

    int cnt = 0;

    for(int i = 0; i < 4; i++){
        int nx = cx + dist[0][i];
        int ny = cy + dist[1][i];

        if(nx < 0 || nx >= c || ny < 0 || ny >= r)
            continue;
        if(visited[ny][nx])
            continue;
        if(map[ny][nx] == 'T')
            continue;

        cnt += DFS(nx, ny, ck + 1);
    }

    visited[cy][cx] = false;
    return cnt;
}

int main(){
    cin >> r >> c >> k;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
        }
    }

    int ans = DFS(0, r - 1, 1);
    cout << ans;
}
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int main(){
    int dist[2][4] = {
        { 1, -1, 0, 0 },
        { 0, 0, 1, -1 }
    };

    int map[101][101] = {};
    int check[101][101] = {};

    int n;
    int m;

    cin >> m >> n;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            map[i][j] = line[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    memset(check, -1, sizeof(check));
    q.emplace(0, 0);
    check[0][0] = 0;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dist[0][i];
            int ny = cy + dist[1][i];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if(check[ny][nx] != -1 && (check[ny][nx] <= check[cy][cx] || (map[ny][nx] == 1 && check[ny][nx] <= check[cy][cx] + 1)))
                continue;

            if(map[ny][nx] == 1)
                    check[ny][nx] = check[cy][cx] + 1;
            else
                check[ny][nx] = check[cy][cx];

            q.emplace(nx, ny);
        }
    }

    cout << check[n - 1][m - 1];
}
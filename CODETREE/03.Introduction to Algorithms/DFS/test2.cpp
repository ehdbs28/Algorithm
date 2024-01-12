#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int m;

int map[51][51] = {};
bool visited[51][51] = {};

int destX[4] = {1, -1, 0, 0};
int destY[4] = {0, 0, 1, -1};

int maxHeight = 1;

int ans = 1;
int safeZone = 0;

void DFS(int x, int y, int k){
    visited[y][x] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if(visited[ny][nx])
            continue;
        if(map[ny][nx] <= k)
            continue;

        DFS(nx, ny, k);
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            maxHeight = max(maxHeight, map[i][j]);
        }
    }

    for(int k = 1; k <= maxHeight; k++){
        memset(visited, false, sizeof(visited));
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visited[i][j] && map[i][j] > k){
                    cnt++;
                    DFS(j, i, k);
                }
            }
        }

        if(cnt > safeZone){
            ans = k;
            safeZone = cnt;
        }
    }

    cout << ans << " " << safeZone;
}
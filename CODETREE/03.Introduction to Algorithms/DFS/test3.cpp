#include <iostream>

using namespace std;

int n;
int map[101][101] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

int cnt = 0;
int maxLen = 0;

int DFS(int x, int y, int t){
    map[y][x] = -1;

    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n){
            continue;
        }
        if(map[ny][nx] != t){
            continue;
        }

        cnt += DFS(nx, ny, t);
    }

    return cnt;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] != -1){
                int len = DFS(j, i, map[i][j]);
                maxLen = max(maxLen, len);
                if(len >= 4){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << " " << maxLen;
}
#include <iostream>
#include <queue>

using namespace std;

int n;
int k;

int map[101][101] = {};
int timeMap[101][101] = {};

int destX[4] = {1, -1, 0, 0};
int destY[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                timeMap[i][j] = -1;
            }
            if(map[i][j] == 2){
                q.emplace(j, i);
            }
        }
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(map[ny][nx] != 1)
                continue;

            map[ny][nx] = 2;
            timeMap[ny][nx] = timeMap[cy][cx] + 1;
            q.emplace(nx, ny);
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == 1){
                cout << -2 << " ";
            }
            else{
                cout << timeMap[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
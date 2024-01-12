#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[26][26] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

int roomCnt = 0;
vector<int> rooms;

int DFS(int x, int y){
    map[y][x] = 0;

    int cnt = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(map[ny][nx] == 0)
            continue;

        cnt += DFS(nx, ny);
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

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == 1){
                roomCnt++;
                rooms.push_back(DFS(j, i));
            }
        }
    }
    sort(rooms.begin(), rooms.end());

    cout << roomCnt << "\n";
    for(auto& room : rooms){
        cout << room << "\n";
    }
}
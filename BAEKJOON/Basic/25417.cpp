#include<iostream>
#include<queue>

using namespace std;

int destX[4] = { 0, 0, 1, -1 };
int destY[4] = { 1, -1, 0, 0 };

int main(){
    int board[5][5] = {};
    bool visited[5][5] = {};

    int r, c;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> board[i][j];
        }
    }

    cin >> r >> c;

    queue<pair<pair<int, int>, int>> q;
    q.push({ {c, r}, 0 });
    visited[r][c] = true;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cd = q.front().second;
        q.pop();

        if(board[cy][cx] == 1){
            cout << cd;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];
            int nd = cd + 1;

            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;

            if(board[ny][nx] == -1)
                continue;

            if(!visited[ny][nx]){
                visited[ny][nx] = true;
                q.push({ {nx, ny }, nd });
            }

            while(nx + destX[i] >= 0 && nx + destX[i] <= 4 && ny + destY[i] >= 0 && ny + destY[i] <= 4 && board[ny][nx] != 7 && board[ny + destY[i]][nx + destX[i]] != -1){
                nx += destX[i];
                ny += destY[i];
            }

            if(!visited[ny][nx] && board[ny][nx] != -1){
                visited[ny][nx] = true;
                q.push({ {nx, ny }, nd });
            }
        }
    }

    cout << -1;
}
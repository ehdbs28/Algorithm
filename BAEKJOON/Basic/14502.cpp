#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n;
int m;

int safe = 0;
int ans = 0;

int board[9][9] = {};
vector<pair<int, int>> virusPos;

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

void BFS(){
    int tempBoard[9][9];
    queue<pair<int, int>> q;
    int temp = safe - 3;
    memcpy(&tempBoard, &board, sizeof(board));

    for(int i = 0; i < virusPos.size(); i++){
        q.push(virusPos[i]);
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if(tempBoard[ny][nx] != 0)
                continue;

            tempBoard[ny][nx] = 2;
            q.emplace(nx, ny);
            --temp;
        }
    }

    ans = max(ans, temp);
}

void make_wall(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                board[i][j] = 1;
                make_wall(cnt + 1);
                board[i][j] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];

            if(board[i][j] == 0){
                ++safe;
            }
            else if(board[i][j] == 2){
                virusPos.emplace_back(j, i);
            }
        }
    }

    make_wall(0);

    cout << ans;
}
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int destX[4] = { -1, 1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

int board[101][101] = {};
int check[101][101] = {};

int n;
int m;

int target = 0;
int answer = 0;

void BFS(){
    queue<pair<int, int>> q;

    q.emplace(0, 0);
    check[0][0] = 1;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pair<int, int> next = { node.first + destX[i], node.second + destY[i] };

            if(next.first < 0 || next.first > m - 1 || next.second < 0 || next.second > n - 1)
                continue;

            if(board[next.second][next.first] == 1){
                check[next.second][next.first]++;
                continue;
            }

            if(check[next.second][next.first] == 1)
                continue;

            check[next.second][next.first] = 1;
            q.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 1)
                ++target;
        }
    }

    while(target != 0){
        memset(check, 0, sizeof(check));

        BFS();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(check[i][j] >= 2){
                    --target;
                    board[i][j] = 0;
                }
            }
        }

        ++answer;
    }

    cout << answer;
}
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int destX[4] = { -1, 1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

int board[101][101] = {};
bool check[101][101] = {};

int n;
int m;

int lastTarget = 0;
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
                board[next.second][next.first] = 0;
                check[next.second][next.first] = true;
                --target;
                continue;
            }

            if(check[next.second][next.first])
                continue;

            check[next.second][next.first] = true;
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
        memset(check, false, sizeof(check));

        lastTarget = target;
        BFS();

        ++answer;
    }

    cout << answer << "\n" << lastTarget;
}
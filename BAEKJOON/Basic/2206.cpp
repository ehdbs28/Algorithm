#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct Val{
    int x;
    int y;
    int dis;
    int broken;
};

int main(){
    int board[1001][1001] = {};
    bool check[1001][1001][2] = {};

    int destX[4] = { -1, 1, 0,0 };
    int destY[4] = { 0, 0, 1, -1 };

    int n;
    int m;

    cin >> n >> m;

    memset(check, false, sizeof(check));

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            board[i][j] = line[j] - '0';
        }
    }

    queue<Val> q;
    q.push({ 0, 0, 0 });
    check[0][0][0] = true;

    while(!q.empty()){
        Val node = q.front();
        q.pop();

        if(node.x == m - 1 && node.y == n - 1){
            cout << node.dis + 1;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            Val next = { node.x + destX[i], node.y + destY[i], node.dis + 1, node.broken };

            if(next.x < 0 || next.x > m - 1 || next.y < 0 || next.y > n - 1)
                continue;

            if(next.broken >= 1 && board[next.y][next.x] == 1)
                continue;

            if(check[next.y][next.x][next.broken])
                continue;

            if(board[next.y][next.x] == 1)
                ++next.broken;

            check[next.y][next.x][next.broken] = true;
            q.push(next);
        }
    }

    cout << -1;
}
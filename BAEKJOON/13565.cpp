#include<iostream>

using namespace std;

int n;
int m;

int board[1001][1001] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

void DFS(int x, int y){
    board[y][x] = 2;

    for(int i = 0; i < 4; i++){
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;

        if(board[ny][nx] != 0)
            continue;

        DFS(nx, ny);
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < m; j++){
            board[i][j] = line[j] - '0';
        }
    }

    for(int i = 0; i < m; i++){
        if(board[0][i] == 0){
            DFS(i, 0);
        }
    }

    for(int i = 0; i < m; i++){
        if(board[n - 1][i] == 2){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}
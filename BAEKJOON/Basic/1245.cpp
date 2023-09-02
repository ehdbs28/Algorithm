#include<iostream>

using namespace std;

int distX[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
int distY[8] = { 0, 0, -1, 1, -1, 1, -1, 1};

int board[101][71] = {};
bool check[101][71] = {};

int n;
int m;

bool isMount = false;

void DFS(int x, int y){
    check[y][x] = true;

    for(int i = 0; i < 8; i++){
        int nX = x + distX[i];
        int nY = y + distY[i];

        if(nX < 0 || nX >= m || nY < 0 || nY >= n)
            continue;

        if(board[y][x] < board[nY][nX])
            isMount = false;

        if(check[nY][nX])
            continue;

        if(board[y][x] == board[nY][nX]){
            DFS(nX, nY);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!check[i][j]){
                isMount = true;
                DFS(j, i);
                if(isMount)
                    ++ans;
            }
        }
    }

    cout << ans;
}
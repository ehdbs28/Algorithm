#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int destX[4] = { -1, 1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

vector<string> board;

int section = 0;
int space = 0;

void DFS(int x, int y, int n, int m){
    ++space;
    board[y][x] = '#';

    for(int i = 0; i < 4; i++){
        int _x = x + destX[i];
        int _y = y + destY[i];

        if(_x < 0 || _x > m - 1 || _y < 0 || _y > n - 1)
            continue;

        if(board[_y][_x] == '#')
            continue;

        DFS(_x, _y, n, m);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int n;
        int m;

        cin >> n >> m;

        board.clear();
        section = 0;
        space = 0;

        for(int i = 0; i < n; i++){
            string line;
            cin >> line;
            board.push_back(line);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '#')
                    continue;

                section++;
                DFS(j, i, n, m);
            }
        }

        cout << section << (section == 1 ? " section, " : " sections, ") << space << (space == 1 ? " space\n" : " spaces\n");
    }
}
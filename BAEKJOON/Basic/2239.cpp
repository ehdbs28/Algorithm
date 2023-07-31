#include<iostream>

using namespace std;

int board[9][9] = {};

bool check(int _i, int _j, int num){
    for(int i = 0; i < 9; i++){
        if(board[i][_j] == num)
            return false;
    }

    for(int j = 0; j < 9; j++){
        if(board[_i][j] == num)
            return false;
    }

    int box_i = _i / 3 * 3;
    int box_j = _j / 3 * 3;

    for(int i = box_i; i < box_i + 3; i++) {
        for (int j = box_j; j < box_j + 3; j++) {
            if(board[i][j] == num)
                return false;
        }
    }

    return true;
}

void func(int i, int j){
    if(j == 9){
        func(i + 1, 0);
        return;
    }

    if(i == 9){
        for(int _i = 0; _i < 9; _i++){
            for(int _j = 0; _j < 9; _j++){
                cout << board[_i][_j];
            }
            cout << "\n";
        }
        exit(0);
    }

    if(board[i][j] != 0){
        func(i, j + 1);
        return;
    }

    for(int n = 1; n < 10; n++){
        if(check(i, j, n)){
            board[i][j] = n;
            func(i, j + 1);
            board[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 9; i++){
        string line;
        cin >> line;
        for(int j = 0; j < 9; j++){
            board[i][j] = line[j] - '0';
        }
    }

    func(0, 0);
}
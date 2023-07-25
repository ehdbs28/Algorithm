#include<iostream>
#include<cstring>

using namespace std;

char map[3600][6200] = {};

void makeTriangle(int i, int j){
    map[i][j + 2] = '*';
    map[i + 1][j + 1] = '*';
    map[i + 1][j + 3] = '*';
    for(int v = 0; v < 5; v++)
        map[i + 2][j + v] = '*';
}

void star(int i, int j, int n){
    if(n == 3){
        makeTriangle(i, j);
        return;
    }

    star(i, j, n / 2);
    star(i + n / 2, j - n / 2, n / 2);
    star(i + n / 2, j + n / 2, n / 2);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;

    cin >> n;

    memset(map, ' ', sizeof(map));
    star(0, n - 3, n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}
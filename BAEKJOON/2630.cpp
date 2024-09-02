#include<iostream>

using namespace std;

int map[129][129] = {};

int white = 0;
int blue = 0;

void Solution(int x, int y, int n){
    int temp = 0;

    for(int i = x; i < x + n; i++)
        for(int j = y; j < y + n; j++)
            temp += map[i][j];

    if(temp == 0){
        ++white;
    }
    else if(temp == n * n){
        ++blue;
    }
    else{
        Solution(x, y, n / 2);
        Solution(x + n / 2, y, n / 2);
        Solution(x, y + n / 2, n / 2);
        Solution(x + n / 2, y + n / 2, n / 2);
    }
}

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> map[i][j];

    Solution(0, 0, n);

    cout << white << "\n" << blue;
}
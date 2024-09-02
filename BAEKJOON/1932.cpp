#include<iostream>

using namespace std;

int main(){
    int tri[501][501] = {};
    int s;
    cin >> s;

    for(int i = 0; i < s; i++){
        for(int j = 0; j <= i; j++){
            cin >> tri[i][j];
        }
    }

    for(int i = s - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            tri[i - 1][j] += max(tri[i][j], tri[i][j + 1]);
        }
    }

    cout << tri[0][0];
}
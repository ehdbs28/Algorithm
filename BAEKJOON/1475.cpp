#include<iostream>
#include<vector>

using namespace std;

int main(){
    int set = 0;

    string num;
    int check[10] = {};

    cin >> num;

    for(char n : num){
        check[n - '0']++;
    }
    check[6] = (check[6] + check[9] + 1) / 2;

    for(int i = 0; i < 9; i++){
        set = max(set, check[i]);
    }

    cout << set;
}
#include<iostream>

using namespace std;

int main(){
    int cases[1001] = { 0, 1, 2 };
    int n;

    cin >> n;

    for(int i = 3; i <= n; i++){
        cases[i] = (cases[i - 1] + cases[i - 2]) % 10007;
    }

    cout << cases[n];
}
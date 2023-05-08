#include<iostream>

using namespace std;

int main(){
    int n;
    int stairs[301] = {};
    int dp[301] = {};

    int answer = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i] + stairs[i - 1]);
    }   

    cout << dp[n];
}
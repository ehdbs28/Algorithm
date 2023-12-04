#include<iostream>

using namespace std;

int dp[1000001] = {};

int main(){
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        dp[i] = 1 + dp[i - 1];

        if(i % 3 == 0)
            dp[i] = min(1 + dp[i / 3], dp[i]);
        if(i % 2 == 0)
            dp[i] = min(1 + dp[i / 2], dp[i]);
    }

    cout << dp[n];
}
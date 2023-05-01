#include<iostream>

using namespace std;

int main(){
    int dp[51] = {1, 1};

    int n;

    cin >> n;

    for(int i = 2; i <= n; i++){
        dp[i] = (dp[i - 2] + dp[i - 1] + 1) % 1000000007;
    }

    cout << dp[n];
}
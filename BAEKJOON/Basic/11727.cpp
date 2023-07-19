#include<iostream>

using namespace std;


int main(){
    int dp[1001] = { 0, 1, 3 };
    int n;

    cin >> n;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cout << dp[n];
}
#include<iostream>

using namespace std;

int main(){
    long long dp[31] = { 0, 0, 3, 0, 11 };
    int n;

    cin >> n;

    if(n % 2 == 1){
        cout << 0;
        return 0;
    }

    for(int i = 6; i <= n; i += 2){
        dp[i] = dp[i - 2] + (dp[i - 2] * 3 - dp[i - 4]);
    }

    cout << dp[n];
}
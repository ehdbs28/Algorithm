#include<iostream>

using namespace std;

int main() {
    long long dp[1001][1001] = {};

    int n, m;
    long long temp = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1)
                temp = 1;
            else
                temp = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];

            dp[i][j] = temp % 1000000007;
        }
    }

    cout << dp[n][m];
}
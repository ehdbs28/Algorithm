#include<iostream>
#include<algorithm>

#define MAX 99999999

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int dp[10001] = {};
    fill(dp, dp + 10001, MAX);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;

        for(int j = coin; j <= k; j++){
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    cout << (dp[k] == MAX ? -1 : dp[k]);
}
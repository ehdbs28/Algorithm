#include<iostream>
#include<climits>

using namespace std;

#define MAX (1000 * 1000 + 1)

int main(){
    int n;
    int cost[1001][3];
    int dp[1001][3];

    int ans = MAX;

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int s = 0; s < 3; s++){
        for(int i = 0; i < 3; i++){
            if(i == s)
                dp[1][i] = cost[1][i];
            else
                dp[1][i] = MAX;
        }

        for(int i = 2; i <= n; i++){
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }

        for(int i = 0; i < 3; i++){
            if(i != s)
                ans = min(ans, dp[n][i]);
        }
    }

    cout << ans;
}
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> coins;
    int dp[10001] = {};

    int n;
    int k;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    for(int i = 1; i <= k; i++){
        if(i % coins[0] == 0){
            dp[i]++;
        }
    }

    for(int i = 1; i < n; i++){
        if(coins[i] > k)
            continue;
        
        dp[coins[i]]++;
        for(int j = coins[i] + 1; j <= k; j++){
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[k];
}
#include<iostream>

using namespace std;

int dp[100001] = { 0, 0, 1, 0, 2, 1 };

int main(){
    int n;
    cin >> n;

    for(int i = 6; i <= n; i++){
        if(dp[i - 2] != 0){
            dp[i] = dp[i - 2] + 1;
        }
        if(dp[i - 5] != 0){
            dp[i] = min(dp[i], dp[i - 5] + 1);
        }
    }

    cout << (dp[n] == 0 ? -1 : dp[n]);
}
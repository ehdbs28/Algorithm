#include<iostream>

using namespace std;

int main(){
    int testCase;
    int n;

    int zero = 0, one = 0;

    pair<int, int> dp[41] = { {1, 0}, {0, 1} };

    for(int i = 2; i <= 40; i++)
        dp[i] = { dp[i - 1].first + dp[i - 2].first, dp[i - 1].second + dp[i - 2].second };

    cin >> testCase;

    while(testCase--){
        cin >> n;
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
}
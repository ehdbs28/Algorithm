#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int dp[100001] = { 0, 1, 2, 3,  };
    fill(&dp[4], &dp[100000], INT_MAX);

    int num;
    int multiple = 1;

    cin >> num;

    for(int i = 4; i <= num; i++){
        multiple = 1;
        for(int j = 1; j <= i / 2 && i - multiple >= 0; j++){
            dp[i] = min(dp[i], 1 + dp[i - multiple]);
            multiple += 3 + (2 * (j - 1));
        }
    }

    cout << dp[num];
}
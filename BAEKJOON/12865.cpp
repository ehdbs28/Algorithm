#include<iostream>

using namespace std;

int dp[101][100001];
pair<int, int> elements[101];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, k;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> elements[i].first >> elements[i].second;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(elements[i].first > j){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - elements[i].first] + elements[i].second);
            }
        }
    }

    cout << dp[n][k];
}
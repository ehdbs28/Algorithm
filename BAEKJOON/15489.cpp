#include <iostream>

using namespace std;

int dp[31][31];

int main(){
    int r, c, w;
    cin >> r >> c >> w;

    for(int i = 0; i < r + w; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < w; i++){
        for(int j = 0; j <= i; j++){
            ans += dp[i + r - 1][j + c - 1];
        }
    }

    cout << ans;
}
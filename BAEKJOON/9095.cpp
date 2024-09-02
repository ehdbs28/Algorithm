#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testCase;
    int dp[12] = { 0, 1, 2, 4 };
    int temp = 7;
    int num;

    cin >> testCase;

    for(int i = 4; i <= 12; i++){
        dp[i] = temp;
        temp -= dp[i - 3];
        temp += dp[i];
    }

    while(testCase--){
        cin >> num;
        cout << dp[num] << "\n";
    }
}
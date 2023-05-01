#include<iostream>

using namespace std;

int main(){
    long long dp[101] = { 0, 1, 1, 1 };

    int testCase;
    int num;

    cin >> testCase;

    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    while(testCase--){
        cin >> num;
        cout << dp[num] << "\n";
    }
}
#include<iostream>

using namespace std;

int main(){
    int dp[1001] = {};

    int num;
    int temp;

    cin >> num;

    for(int i = 2; i <= num; i++){
        dp[i] = 1 + dp[i - 1];

        if(i % 3 == 0)
            dp[i] = min(1 + dp[i / 3], dp[i]);
        if(i % 2 == 0)
            dp[i] = min(1 + dp[i / 2], dp[i]);
    }

    cout << dp[num];
}
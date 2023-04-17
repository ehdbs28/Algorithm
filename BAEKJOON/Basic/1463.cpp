#include<iostream>

using namespace std;

int main(){
    int dp[1001] = {};

    int num;
    int temp;

    cin >> num;

    for(int i = 2; i <= num; i++){
        temp = 1 + dp[i - 1];

        if(i <= 3)
            dp[i] = 1;
        else if(i % 6 == 0)
            dp[i] = min(min(1 + dp[i / 3], 1 + dp[i / 2]), temp);
        else if(i % 3 == 0)
            dp[i] = min(1 + dp[i / 3], temp);
        else if(i % 2 == 0)
            dp[i] = min(1 + dp[i / 2], temp);
        else
            dp[i] = temp;
    }

    cout << dp[num];
}
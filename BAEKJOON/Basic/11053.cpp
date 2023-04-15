#include<iostream>

using namespace std;

int main(){
    int nums[1000] = {};
    int dp[1001] = {};

    int lenght;

    int answer = 0;

    cin >> lenght;

    for(int i = 0; i < lenght; i++){
        cin >> nums[i];

        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if(dp[i] == 0) dp[i] = 1;

        answer = max(answer, dp[i]);
    }

    cout << answer;
}
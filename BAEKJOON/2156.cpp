#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001] = {};
int dp[10002] = {};

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dp[1] = arr[0];
    dp[2] = arr[0] + arr[1];

    for(int i = 3; i <= n; i++)
    {
        int ri = i - 1;
        dp[i] = max(dp[i - 2] + arr[ri], max(dp[i - 3] + arr[ri - 1] + arr[ri], dp[i - 1]));
    }

    cout << dp[n];
}
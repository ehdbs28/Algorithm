#include <iostream>

using namespace std;

int n;
long long s;

int arr[100001] = {};
long long prefix_sum[100001] = {};

int ans = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    if(prefix_sum[n] < s)
    {
        cout << 0;
        return 0;
    }

    int left = 1, right = 1;
    while(left <= n && right <= n)
    {
        long long sum = prefix_sum[right] - prefix_sum[left - 1];
        int len = right - left + 1;

        if(sum >= s)
        {
            left++;
            ans = min(ans, len);
        }
        else
        {
            right++;
        }
    }

    cout << ans;
}
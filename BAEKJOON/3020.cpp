#include <iostream>
#include <climits>

using namespace std;

int n;
int h;

int top[500001] = {};
int bottom[500001] = {};

int top_prefixSum[500001] = {};
int bottom_prefixSum[500001] = {};

int ans = INT_MAX;
int ansCnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> h;
    for(int i = 1; i <= n; i++)
    {
        int blockSize;
        cin >> blockSize;
        if(i % 2 == 1)
        {
            bottom[blockSize]++;
        }
        else
        {
            top[h + 1 - blockSize]++;
        }
    }

    for(int i = h; i >= 1; i--)
    {
        bottom_prefixSum[i] = bottom_prefixSum[i + 1] + bottom[i];
    }
    for(int i = 1; i <= h; i++)
    {
        top_prefixSum[i] = top_prefixSum[i - 1] + top[i];
    }

    for(int i = 1; i <= h; i++)
    {
        const int sum = bottom_prefixSum[i] + top_prefixSum[i];

        if(sum == ans)
        {
            ansCnt++;
        }

        if(sum < ans)
        {
            ans = sum;
            ansCnt = 1;
        }
    }

    cout << ans << " " << ansCnt;
}
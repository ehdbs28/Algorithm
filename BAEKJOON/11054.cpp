#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[1001] = {};

    int iDP[1001] = {};
    int dDP[1001] = {};

    int answer = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // lis
    for(int i = 0; i < n; i++)
    {
        iDP[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            {
                iDP[i] = max(iDP[i], iDP[j] + 1);
            }
        }
    }

    // lds
    for(int i = n - 1; i >= 0; i--)
    {
        dDP[i] = 1;
        for(int j = n - 1; j > i; j--)
        {
            if(a[i] > a[j])
            {
                dDP[i] = max(dDP[i], dDP[j] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        answer = max(answer, iDP[i] + dDP[i] - 1);
    }

    cout << answer;
}
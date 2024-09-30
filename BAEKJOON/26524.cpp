#include <iostream>

#define MOD 1000000007

using namespace std;

int main()
{
    int n;
    long long ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        ans = (ans * i) % MOD;
    }
    cout << ans;
}
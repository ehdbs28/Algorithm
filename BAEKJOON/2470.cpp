#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

typedef long long ll;
#define INF 2000000000

using namespace std;

int main()
{
    int n;
    vector<ll> vec;

    cin >> n;
    vec.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = n - 1;
    ll min = INF;
    ll answer[2];

    while(left < right)
    {
        ll lv = vec[left];
        ll rv = vec[right];

        ll sum = lv + rv;

        if(min > abs(sum))
        {
            answer[0] = lv;
            answer[1] = rv;
            min = abs(sum);

            if(sum == 0)
                break;
        }

        if(sum > 0)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }

    cout << answer[0] << " " << answer[1];
}
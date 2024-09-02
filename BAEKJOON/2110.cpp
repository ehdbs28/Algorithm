#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int c;

vector<int> houses;

int GetInstallCount(int targetDistance)
{
    int cnt = 1;
    int lastLocation = houses[0];

    for(int i = 1; i < n; i++)
    {
        int location = houses[i];
        int distance = location - lastLocation;

        if(distance >= targetDistance)
        {
            cnt++;
            lastLocation = location;
        }
    }

    return cnt;
}

int main()
{
    cin >> n >> c;
    houses.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> houses[i];
    }

    sort(houses.begin(), houses.end());

    int low = 1;
    int high = houses[n - 1] - houses[0] + 1;

    while(low < high)
    {
        int mid = (low + high) / 2;
        int installCnt = GetInstallCount(mid);

        if(installCnt >= c)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

    cout << low - 1;
}


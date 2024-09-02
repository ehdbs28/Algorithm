#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n;
int m;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

vector<bool> check;

int answer = INT_MAX;

int GetChickenDis()
{
    int dis = 0;

    for(const auto& house : houses)
    {
        int minDis = INT_MAX;
        for(int i = 0; i < chickens.size(); i++)
        {
            if(check[i])
            {
                auto chicken = chickens[i];
                int curDis = abs(house.first - chicken.first) + abs(house.second - chicken.second);

                if(curDis < minDis)
                {
                    minDis = curDis;
                }
            }
        }
        dis += minDis;
    }

    return dis;
}

void BackTracking(int lastIndex, int size)
{
    if(size >= m)
    {
        int dis = GetChickenDis();
        if(dis < answer)
        {
            answer = dis;
        }
        return;
    }

    for(int i = lastIndex; i < chickens.size(); i++)
    {
        if(!check[i])
        {
            check[i] = true;
            BackTracking(i, size + 1);
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int info;
            cin >> info;

            if(info == 1)
            {
                houses.emplace_back(j, i);
            }
            else if(info == 2)
            {
                chickens.emplace_back(j, i);
            }
        }
    }

    check.resize(chickens.size(), false);
    BackTracking(0, 0);

    cout << answer;
}
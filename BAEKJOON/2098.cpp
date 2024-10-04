#include <iostream>
#include <memory.h>

using namespace std;

#define INF 987654321;

int n;
int map[16][16];
int dp[16][1 << 16];

int dfs(int cur, int visit)
{
    if(visit == (1 << n)-1)
    {
        if(map[cur][0] == 0)
        {
            return INF;
        }
        return map[cur][0];
    }

    if(dp[cur][visit] != -1)
    {
        return dp[cur][visit];
    }

    dp[cur][visit] = INF;

    for(int i = 0; i < n; i++)
    {
        if(map[cur][i] == 0)
        {
            continue;
        }

        if((visit & (1 << i)) == (1 << i))
        {
            continue;
        }

        dp[cur][visit] = min(dp[cur][visit], map[cur][i] + dfs(i, visit | 1 << i));
    }

    return dp[cur][visit];
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);
}
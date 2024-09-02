#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    int map[1001] = {};
    int check[1001] = {};

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> map[i];
        check[i] = -1;
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    check[0] = 0;

    while(!q.empty())
    {
        int cur = q.front().first;
        int j = q.front().second;
        q.pop();

        for(int i = 1; i <= map[cur]; i++)
        {
            int next = cur + i;

            if(next >= n)
                continue;
            if(check[next] != -1 && check[next] <= j + 1)
                continue;

            check[next] = j + 1;
            q.emplace(next, j + 1);
        }
    }

    cout << check[n - 1];
}
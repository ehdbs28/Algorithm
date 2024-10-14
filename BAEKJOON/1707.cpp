#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

int v, e;
vector<int> graph[20001] = {};
int visited[20001] = {};

bool bfs(queue<pair<int, int>> q, int s)
{

    // 0 : blue / 1 : red
    q.emplace(s, 0);
    visited[1] = 0;

    while(!q.empty())
    {
        int v = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < graph[v].size(); i++)
        {
            int n = graph[v][i];
            int nc = c == 0 ? 1 : 0;

            if(visited[n] != -1)
            {
                if(visited[n] == c)
                {
                    return false;
                }
                continue;
            }

            visited[n] = nc;
            q.emplace(n, nc);
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        cin >> v >> e;

        for(int i = 1; i <= v; i++)
        {
            graph[i].clear();
        }

        for(int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<pair<int, int>> q;
        memset(visited, -1, sizeof(visited));
        bool b = true;

        for(int i = 1; i <= v; i++)
        {
            if(visited[i] == -1 && !bfs(q, i))
            {
                b = false;
                break;
            }
        }

        cout << (b ? "YES" : "NO") << "\n";
    }
}
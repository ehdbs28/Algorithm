#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX 101

int N, M, K;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int map[MAX][MAX];
int visit[MAX][MAX];

int Dfs(int x, int y)
{
    int cnt = 1;
    stack<pair<int, int>> s;
    s.push({x , y});
    visit[x][y] = 1;
    while (!s.empty())
    {
        pair<int, int> cur = s.top();
        s.pop();
        if (visit[cur.X][cur.Y] == 0)
            cnt++;
        visit[cur.X][cur.Y] = 1;


        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (map[nx][ny] == 1 || visit[nx][ny] == 1)
                continue;

            s.push({ nx, ny });
        }
    }
    return cnt;
}

int main()
{
    vector<int> v;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                map[x][y] = 1;
            }
        }
    }

    for (int y = M - 1; y >= 0; y--)
    {
        for (int x = 0; x < N; x++)
        {
            if (map[x][y] == 0 && visit[x][y] == 0)
            {
                v.push_back(Dfs(x, y));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
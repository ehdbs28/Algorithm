#include <iostream>
#include <memory.h>

using namespace std;

int destX[4] = { 0, 0, 1, -1 };
int destY[4] = { 1, -1, 0, 0 };

int n;
int maxDepth;
int answer = 1;

int depth[101][101] = {};
bool visited[101][101] = {};

void DFS(int x, int y, int checkDepth)
{
    visited[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if(visited[ny][nx])
            continue;
        if(depth[ny][nx] <= checkDepth)
            continue;

        DFS(nx, ny, checkDepth);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> depth[i][j];
            maxDepth = max(maxDepth, depth[i][j]);
        }
    }

    while(maxDepth > 0)
    {
        memset(visited, false, sizeof(visited));
        int space = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j])
                    continue;
                if(depth[i][j] <= maxDepth)
                    continue;

                DFS(j, i, maxDepth);
                space++;
            }
        }

        answer = max(answer, space);
        maxDepth--;
    }

    cout << answer;
}
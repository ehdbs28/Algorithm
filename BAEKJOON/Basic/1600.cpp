#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

short default_dest_x[4] = { 0, 0, 1, -1 };
short default_dest_y[4] = { 1, -1, 0, 0 };

short horse_dest_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
short horse_dest_y[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int k, w, h;

int map[201][201] = {};
int visited[31][201][201] = {};

queue<pair<int, pair<int, int>>> q;

bool IsCorrectPoint(int cj, int cx, int cy, int nj, int nx, int ny)
{
    if(nx < 0 || nx >= w || ny < 0 || ny >= h)
    {
        return false;
    }

    if(map[ny][nx] == 1)
    {
        return false;
    }

    if(visited[nj][ny][nx] != 0 && visited[nj][ny][nx] <= visited[cj][cy][cx] + 1)
    {
        return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> w >> h;

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> map[i][j];
        }
    }

    visited[0][0][0] = 1;
    q.push({0,{0, 0}});

    while(!q.empty())
    {
        int cj = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cx + default_dest_x[i];
            int ny = cy + default_dest_y[i];

            if(!IsCorrectPoint(cj, cx, cy, cj, nx, ny))
            {
                continue;
            }

            visited[cj][ny][nx] = visited[cj][cy][cx] + 1;
            q.push({cj, {nx, ny}});
        }

        if(cj >= k)
        {
            continue;
        }

        for(int i = 0; i < 8; i++)
        {
            int nx = cx + horse_dest_x[i];
            int ny = cy + horse_dest_y[i];

            if(!IsCorrectPoint(cj, cx, cy, cj + 1, nx, ny))
            {
                continue;
            }

            visited[cj + 1][ny][nx] = visited[cj][cy][cx] + 1;
            q.push({cj + 1, {nx, ny}});
        }
    }

    int min = INT_MAX;

    for(int i = 0; i <= k; i++)
    {
        if(visited[i][h - 1][w - 1] != 0 && min > visited[i][h - 1][w - 1])
        {
            min = visited[i][h - 1][w - 1];
        }
    }

    cout << (min == INT_MAX ? -1 : min - 1);
}
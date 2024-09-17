#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct Pos
{
    int x;
    int y;
};

int n;

int board[21][21] = {};
int visited[21][21] = {};

int destX[4] = {-1, 1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

Pos sharkPos;

int currentSharkSize = 2;
int remainCntSizeUp = currentSharkSize;

int duringTime = 0;

void BFS(vector<Pos>& feedVec)
{
    memset(visited, 0, sizeof(visited));

    queue<Pos> q;
    q.push(sharkPos);
    visited[sharkPos.y][sharkPos.x] = 1;

    while(!q.empty())
    {
        const Pos p = q.front();
        const int c = visited[p.y][p.x];
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            const Pos next = {p.x + destX[i], p.y + destY[i]};

            if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= n)
            {
                continue;
            }

            if(visited[next.y][next.x] != 0)
            {
                continue;
            }

            if(board[next.y][next.x] > currentSharkSize)
            {
                continue;
            }

            visited[next.y][next.x] = c + 1;
            q.push(next);

            if(board[next.y][next.x] != 0 && board[next.y][next.x] < currentSharkSize)
            {
                feedVec.push_back(next);
            }
        }
    }
}

void Solve()
{
    vector<Pos> feedVec;

    while(true)
    {
        feedVec.clear();
        BFS(feedVec);

        if(feedVec.empty())
        {
            break;
        }

        Pos feed = feedVec.front();
        int minDistance = visited[feed.y][feed.x];

        for(int i = 1; i < feedVec.size(); i++)
        {
            const int distance = visited[feedVec[i].y][feedVec[i].x];

            if(distance < minDistance)
            {
                feed = feedVec[i];
                minDistance = distance;
            }
            else if(distance == minDistance)
            {
                if(feed.y > feedVec[i].y)
                {
                    feed = feedVec[i];
                }
                else if(feed.y == feedVec[i].y)
                {
                    if(feed.x > feedVec[i].x)
                    {
                        feed = feedVec[i];
                    }
                }
            }
        }

        board[feed.y][feed.x] = 0;
        sharkPos = feed;

        duringTime += minDistance - 1;

        remainCntSizeUp--;
        if(remainCntSizeUp == 0)
        {
            currentSharkSize++;
            remainCntSizeUp = currentSharkSize;
        }
    }
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if(board[i][j] == 0)
            {
                continue;
            }

            if(board[i][j] == 9)
            {
                sharkPos = {j, i};
                board[i][j] = 0;
            }
        }
    }

    Solve();
    cout << duringTime;
}
#include <iostream>
#include <queue>

using namespace std;

struct Step
{
    int rx, ry;
    int bx, by;
    int t;
};

int n;
int m;

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

char board[11][11] = {};
bool visited[11][11][11][11] = {};

void Move(int& rx, int& ry, int& distance, int& i)
{
    while(board[rx + destX[i]][ry + destY[i]] != '#' && board[rx][ry] != 'O')
    {
        rx += destX[i];
        ry += destY[i];
        distance++;
    }
}

int main()
{
    cin >> n >> m;
    int rx, ry, bx, by;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            if(board[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    queue<Step> q;
    q.push({ rx, ry, bx, by, 0 });
    visited[rx][ry][bx][by] = true;
    while(!q.empty())
    {
        rx = q.front().rx;
        ry = q.front().ry;
        bx = q.front().bx;
        by = q.front().by;
        int t = q.front().t;
        q.pop();

        if(t >= 10)
        {
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, nt = t + 1;

            Move(nrx, nry, rc, i);
            Move(nbx, nby, bc, i);

            if(board[nbx][nby] == 'O')
            {
                continue;
            }
            if(board[nrx][nry] == 'O')
            {
                cout << nt;
                return 0;
            }

            if(nrx == nbx && nry == nby)
            {
                if(rc > bc)
                {
                    nrx -= destX[i];
                    nry -= destY[i];
                }
                else
                {
                    nbx -= destX[i];
                    nby -= destY[i];
                }
            }

            if (visited[nrx][nry][nbx][nby])
            {
                continue;
            }

            visited[nrx][nry][nbx][nby] = true;
            q.push({ nrx,nry,nbx,nby,nt });
        }
    }

    cout << -1;
}
#include<iostream>
#include<memory.h>

using namespace std;

int destX[4] = {0, 0, 1, -1};
int destY[4] = {1, -1, 0, 0};

int n;
int m;

int year = 0;

int board[301][301] = {};
int temp[301][301];
bool check[301][301] = {};

void DFS(int x, int y, bool iceBreak)
{
    check[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + destX[i];
        int ny = y + destY[i];

        if(nx < 0 || nx >= m || ny < 0 || ny >= n)
            continue;
        if(check[ny][nx])
            continue;

        if(iceBreak)
        {
            if(board[ny][nx] > 0)
            {
                temp[ny][nx]--;
                continue;
            }
        }
        else
        {
            if(board[ny][nx] <= 0)
            {
                continue;
            }
        }

        DFS(nx, ny, iceBreak);
    }
}

void IceBreak()
{
    memset(check, false, sizeof(check));
    memcpy(temp, board, sizeof(board));

    year++;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 0 && !check[i][j])
            {
                DFS(j, i, true);
            }
        }
    }

    memcpy(board, temp, sizeof(board));
}

int GetBergCnt()
{
    int returnVal = 0;
    memset(check, false, sizeof(check));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] > 0 && !check[i][j])
            {
                returnVal++;
                DFS(j, i, false);
            }
        }
    }

    return returnVal;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    do
    {
        IceBreak();
    }
    while(GetBergCnt() < 2 && GetBergCnt() != 0);

    if(GetBergCnt() == 0)
    {
        cout << 0;
    }
    else
    {
        cout << year;
    }
}
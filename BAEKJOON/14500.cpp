#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

int board[501][501] = {};
int check[501][501] = {};

int n;
int m;

int answer = 0;

void DFS(int x, int y, int depth, int sum)
{
    if(depth >= 3)
    {
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        int _x = x + destX[i];
        int _y = y + destY[i];

        if(_x < 0 || _x > m - 1 || _y < 0 || _y > n - 1)
            continue;

        if(check[_y][_x] == true)
            continue;
        
        check[_y][_x] = true;
        DFS(_x, _y, depth + 1, sum + board[_y][_x]);
        check[_y][_x] = false;
    }
}

void specialShape(int x, int y)
{
    priority_queue<int> vals;
    int sum = board[y][x];

    for(int i = 0; i < 4; i++)
    {
        int _x = x + destX[i];
        int _y = y + destY[i];

        if(_x < 0 || _x > m - 1 || _y < 0 || _y > n - 1)
            continue;

        vals.push(board[_y][_x]);
    }

    if(vals.size() >= 3)
    {
        for(int i = 0; i < 3; i++)
        {
            sum += vals.top();
            vals.pop();
        }
        answer = max(answer, sum); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            check[i][j] = true; 
            DFS(j, i, 0, board[i][j]);
            specialShape(j, i);
            check[i][j] = false;
        }
    }

    cout << answer;
}
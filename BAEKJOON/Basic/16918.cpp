#include <iostream>
#include <queue>

using namespace std;

int h, w, n;
char board[200][200] = {};

queue<class Bomb*> bombs;

int destX[4] = {0, 0, 1, -1};
int destY[4] = {1, -1, 0, 0};

class Bomb
{
public:
    Bomb(int createTime, int x, int y)
    {
        _createTime = createTime;
        _x = x;
        _y = y;
    }

public:
    void Explosion()
    {
        board[_y][_x] = '.';
        for(int i = 0; i < 4; i++)
        {
            int nx = _x + destX[i];
            int ny = _y + destY[i];

            if(nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;

            board[ny][nx] = '.';
        }
    }

    inline const bool IsReadyToExplosion(const int curTime) const
    {
        return _createTime + 3 == curTime;
    }

    inline const bool AlreadyDestroyBomb() const
    {
        return board[_y][_x] != 'O';
    }

private:
    int _createTime;
    int _x;
    int _y;

};

void DrawBoard()
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void CreateBomb(int curTime)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(board[i][j] == '.')
            {
                board[i][j] = 'O';
                bombs.push(new Bomb(curTime, j, i));
            }
        }
    }
}

void ExplosionAllBomb(int curTime)
{
    while(!bombs.empty())
    {
        if(!bombs.front()->IsReadyToExplosion(curTime))
        {
            break;
        }

        Bomb* bomb = bombs.front();
        bombs.pop();

        bomb->Explosion();
    }

    queue<Bomb*> tempBombs;
    while(!bombs.empty())
    {
        if(!bombs.front()->AlreadyDestroyBomb())
        {
            tempBombs.push(bombs.front());
        }
        bombs.pop();
    }
    bombs = tempBombs;
}

int main()
{
    cin >> h >> w >> n;

    for(int i = 0; i < h; i++)
    {
        char line[w];
        cin >> line;

        for(int j = 0; j < w; j++)
        {
            board[i][j] = line[j];
            if(board[i][j] == 'O')
            {
                bombs.push(new Bomb(0, j, i));
            }
        }
    }

    if(n <= 1)
    {
        DrawBoard();
        return 0;
    }

    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            CreateBomb(i);
        }
        else
        {
            ExplosionAllBomb(i);
        }
    }

    DrawBoard();
}
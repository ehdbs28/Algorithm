#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int dest[4][2] = {
    { 0, -1 },
    { 1, 0 },
    { 0, 1 },
    { -1, 0 }
};

int curDir = 1;

int n;
int board[101][101] = {};
deque<pair<int, int>> snakes;

vector<pair<int, char>> orders;
int orderIndex = 0;

bool IsBreak(int nx, int ny)
{
    if(nx < 0 || nx >= n || ny < 0 || ny >= n)
        return true;

    for(const auto& snake : snakes)
    {
        if(snake.first == nx && snake.second == ny)
        {
            return true;
        }
    }

    return false;
}

bool IsApple(int nx, int ny)
{
    return board[ny][nx] == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int k;
    cin >> k;

    for(int i = 0; i < k; i++)
    {
        int ax, ay;
        cin >> ay >> ax;
        board[ay-1][ax-1] = 1;
    }

    int l;
    cin >> l;

    for(int i = 0; i < l; i++)
    {
        int t;
        char c;
        cin >> t >> c;
        orders.emplace_back(t, c);
    }

    snakes.emplace_back(0, 0);

    int t = 0;
    while(true)
    {
        t++;

        pair<int, int> head = snakes.back();
        int nx = head.first + dest[curDir][0];
        int ny = head.second + dest[curDir][1];
        snakes.pop_back();

        if(IsBreak(nx, ny))
        {
            break;
        }

        if(!IsApple(nx, ny))
        {
            if(!snakes.empty())
            {
                snakes.pop_front();
                snakes.push_back(head);
            }
        }
        else
        {
            board[ny][nx] = 0;
            snakes.push_back(head);
        }

        snakes.emplace_back(nx, ny);

        if(t == orders[orderIndex].first)
        {
            if(orders[orderIndex].second == 'D')
            {
                curDir = (curDir + 1) % 4;
            }
            else if(orders[orderIndex].second == 'L')
            {
                curDir--;
                if(curDir < 0)
                {
                    curDir = 3;
                }
            }

            orderIndex++;
        }
    }

    cout << t;
}
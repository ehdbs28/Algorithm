#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x;
    int y;
    int r;

    pair<int, int> GetLastPoint() const
    {
        switch (r)
        {
            case 0:
                return {x + 1, y};
            case 1:
                return {x + 1, y + 1};
            case 2:
                return {x, y + 1};
            default:
                return {};
        }
    }

    vector<pair<int, int>> GetRotateInfo() const
    {
        switch (r)
        {
        case 0:
            return { {x+1, y} };
        case 1:
            return { {x+1, y+1}, {x+1, y+0}, {x+0, y+1} };
        case 2:
            return { {x+0, y+1} };
        default:
            return {};
        }
    }
};

struct DestInfo
{
    int nx;
    int ny;
    int nr;
};

vector<DestInfo> dest[3] = {
    {
        { 1, 0, 0 },
        { 1, 0, 1 }
    },
    {
        { 1, 1, 0 },
        { 1, 1, 2 },
        { 1, 1, 1 }
    },
    {
        {0, 1, 2 },
        {0, 1, 1 }
    }
};

int n;
int board[17][17] = {};

int answer = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    if(board[n - 1][n - 1] == 1)
    {
        cout << 0;
        return 0;
    }

    queue<Node> q;
    q.push({ 0, 0, 0 });

    while(!q.empty())
    {
        const Node cur = q.front();
        q.pop();

        const pair<int, int> cLastPoint = cur.GetLastPoint();
        if(cLastPoint.first == n - 1 && cLastPoint.second == n - 1)
        {
            answer++;
            continue;
        }

        for(int i = 0; i < dest[cur.r].size(); i++)
        {
            const DestInfo info = dest[cur.r][i];
            const Node next = {cur.x + info.nx, cur.y + info.ny, info.nr};

            const vector<pair<int, int>> nRotateInfo = next.GetRotateInfo();
            bool isValid = false;

            for(const auto& rot : nRotateInfo)
            {
                isValid = false;

                if(rot.first < 0 || rot.first >= n || rot.second < 0 || rot.second >= n)
                {
                    break;
                }
                if(board[rot.second][rot.first] == 1)
                {
                    break;
                }

                isValid = true;
            }

            if(isValid)
            {
                q.push(next);
            }
        }
    }

    cout << answer;
}
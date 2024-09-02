#include<iostream>
#include<queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int box[1000][1000] = {};

    int destX[4] = { 0, 0, -1, 1 };
    int destY[4] = { -1, 1, 0, 0 };

    int n;
    int m;

    int day = 0;

    queue<pair<int, int>> check;

    cin >> n >> m;

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> box[i][j];

            if(box[i][j] == 1)
            {
                check.push({ j , i });
            }
        }
    }

    while(check.empty() == false)
    {
        pair<int, int> node = check.front();
        check.pop();

        for(int i = 0; i < 4; ++i)
        {
            int x = node.first + destX[i];
            int y = node.second + destY[i];

            if(x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if(box[y][x] == -1)
                continue;
            if(box[y][x] != 0 && box[y][x] <= box[node.second][node.first] + 1)
                continue;

            box[y][x] = box[node.second][node.first] + 1;
            check.push({ x, y });
        }
    }   

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(box[i][j] == 0)
            {
                cout << -1;
                return 0;
            }

            if(box[i][j] > 0)
            {
                day = max(day, box[i][j]);
            }
        }
    } 

    cout << day - 1;
}
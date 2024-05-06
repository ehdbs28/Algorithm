#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int destX[4] = {0, 0, 1, -1};
int destY[4] = {1, -1, 0, 0};

pair<int, int> redS, redE, blueS, blueE;

int solution(vector<vector<int>> maze) {
    int height = maze.size();
    int width = maze[0].size();

    vector<vector<vector<int>>> check(2, vector<vector<int>>(4, vector<int>(4)));

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(maze[i][j] == 1) redS = {j, i};
            else if(maze[i][j] == 2) blueS = {j, i};
            else if(maze[i][j] == 3) redE = {j, i};
            else if(maze[i][j] == 4) blueE = {j, i};
        }
    }

    queue<vector<pair<int, int>>> q;
    queue<vector<vector<vector<int>>>> vq;

    q.push({ redS, blueS });

    check[0][redS.second][redS.first] = 1;
    check[1][blueS.second][blueS.first] = 1;

    vq.push({ check[0], check[1] });

    bool completeR, completeB;

    while(!q.empty() && !vq.empty())
    {
        completeR = false;
        completeB = false;

        int rx = q.front()[0].first;
        int ry = q.front()[0].second;

        int bx = q.front()[1].first;
        int by = q.front()[1].second;

        check[0] = vq.front()[0];
        check[1] = vq.front()[1];

        q.pop();
        vq.pop();

        if(rx == redE.first && ry == redE.second)
            completeR = true;
        if(bx == blueE.first && by == blueE.second)
            completeB = true;

        if(completeR && completeB)
            break;

        if(!completeR && !completeB)
        {
            for(int i = 0; i < 4; i++)
            {
                int rnx = rx + destX[i];
                int rny = ry + destY[i];

                if(rnx < 0 || rnx > width - 1 || rny < 0 || rny > height - 1)
                    continue;
                if(check[0][rny][rnx] != 0)
                    continue;
                if(maze[rny][rnx] == 5)
                    continue;

                for(int j = 0; j < 4; j++)
                {
                    int bnx = bx + destX[j];
                    int bny = by + destY[j];

                    if(bnx < 0 || bnx > width - 1 || bny < 0 || bny > height - 1)
                        continue;
                    if(check[1][bny][bnx] != 0)
                        continue;
                    if(maze[bny][bnx] == 5)
                        continue;

                    if(rnx == bnx && rny == bny)
                        continue;
                    if(rnx == bx && rny == by && bnx == rx && bny == ry)
                        continue;

                    q.push({ {rnx, rny}, {bnx, bny} });
                    check[0][rny][rnx] = check[0][ry][rx] + 1;
                    check[1][bny][bnx] = check[1][by][bx] + 1;
                    vq.push({ check[0], check[1] });
                    check[0][rny][rnx] = 0;
                    check[1][bny][bnx] = 0;
                }
            }
        }
        else if(!completeR)
        {
            for(int j = 0; j < 4; j++)
            {
                int rnx = rx + destX[j];
                int rny = ry + destY[j];

                if(rnx < 0 || rnx > width - 1 || rny < 0 || rny > height - 1)
                    continue;
                if(check[0][rny][rnx] != 0)
                    continue;
                if(maze[rny][rnx] == 5)
                    continue;
                if(rnx == bx && rny == by)
                    continue;

                q.push({ {rnx, rny}, {bx, by} });
                check[0][rny][rnx] = check[0][ry][rx] + 1;
                vq.push({ check[0], check[1] });
                check[0][rny][rnx] = 0;
            }
        }
        else if(!completeB)
        {
            for(int j = 0; j < 4; j++)
            {
                int bnx = bx + destX[j];
                int bny = by + destY[j];

                if(bnx < 0 || bnx > width - 1 || bny < 0 || bny > height - 1)
                    continue;
                if(check[1][bny][bnx] != 0)
                    continue;
                if(maze[bny][bnx] == 5)
                    continue;
                if(bnx == rx && bny == ry)
                    continue;

                q.push({ {rx, ry}, {bnx, bny} });
                check[1][bny][bnx] = check[1][by][bx] + 1;
                vq.push({ check[0], check[1] });
                check[1][bny][bnx] = 0;
            }
        }
    }

    if(!completeR || !completeB)
    {
        return 0;
    }
    else
    {
        return max(check[0][redE.second][redE.first] - 1, check[1][blueE.second][blueE.first] - 1);
    }
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 5, 2},
        {0, 3, 0, 0},
        {0, 4, 5, 0},
        {0, 0, 0, 0},
    };
    vector<vector<int>> maze2 = {{1, 0, 2}, {0, 0, 0}, {5, 0, 5}, {4, 0, 3}};
    cout << solution(maze2);
}
#include<vector>
#include<queue>

using namespace std;

int distX[4] = { -1, 1, 0, 0 };
int distY[4] = { 0, 0, -1, 1 };

int solution(vector<vector<int>> maps)
{
    int col = maps.size();
    int row = maps[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> check;
    check.resize(col);
    for(int i = 0; i < col; i++){
        check[i] = vector<int>(row, -1);
    }

    q.emplace(0, 0);
    check[0][0] = 1;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = node.first + distX[i];
            int nextY = node.second + distY[i];
            int nextDis = check[node.second][node.first] + 1;

            if(nextX < 0 || nextX >= row || nextY < 0 || nextY >= col)
                continue;

            if(maps[nextY][nextX] != 1)
                continue;

            if(check[nextY][nextX] != -1 && check[nextY][nextX] <= nextDis)
                continue;

            check[nextY][nextX] = nextDis;
            q.emplace(nextX, nextY);
        }
    }

    return check[col - 1][row - 1];
}
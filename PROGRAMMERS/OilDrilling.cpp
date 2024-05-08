#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> map;
vector<int> oils = {};
vector<bool> visited = {};

int width, height;
int oilCnt;

int destX[4] = {0, 0, 1, -1};
int destY[4] = {1, -1, 0, 0};

int DFS(int x, int y, int i)
{
    map[y][x] = i;

    int size = 1;
    for(int j = 0; j < 4; j++)
    {
        int nx = x + destX[j];
        int ny = y + destY[j];

        if(nx < 0 || nx >= width || ny < 0 || ny >= height)
            continue;
        if(map[ny][nx] == -2 || map[ny][nx] == i)
            continue;

        size += DFS(nx, ny, i);
    }

    return size;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    height = land.size();
    width = land[0].size();

    map.resize(height, vector<int>(width, -2));

    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (land[i][j] == 1)
            {
                map[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(land[i][j] == 1 && map[i][j] == -1)
            {
                oils.push_back(DFS(j, i, oilCnt));
                oilCnt++;
            }
        }
    }

    for(int j = 0; j < width; j++)
    {
        int oil = 0;
        visited = vector<bool>(oils.size(), false);
        for(int i = 0; i < height; i++)
        {
            if(map[i][j] != -2 && !visited[map[i][j]])
            {
                oil += oils[map[i][j]];
                visited[map[i][j]] = true;
            }
        }

        if(oil > answer)
        {
            answer = oil;
        }
    }

    return answer;
}

int main()
{
    cout << solution({
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1}
    });
}
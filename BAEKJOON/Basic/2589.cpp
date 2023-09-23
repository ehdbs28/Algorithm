#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n;
int m;

vector<string> map;
int check[51][51] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

int dis = 0;
int ans = 0;

void BFS(int x, int y){
    queue<pair<int, int>> q;
    q.emplace(x, y);

    dis = 0;
    memset(check, -1, sizeof(check));
    check[y][x] = 0;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int _x = node.first + destX[i];
            int _y = node.second + destY[i];

            if(_x < 0 || _x >= m || _y < 0 || _y >= n)
                continue;

            if(check[_y][_x] != -1)
                continue;

            if(map[_y][_x] != 'L')
                continue;

            check[_y][_x] = check[node.second][node.first] + 1;
            dis = max(dis, check[_y][_x]);
            q.emplace(_x, _y);
        }
    }

    ans = max(ans, dis);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        map.push_back(line);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 'L'){
                BFS(j, i);
            }
        }
    }

    cout << ans;
}
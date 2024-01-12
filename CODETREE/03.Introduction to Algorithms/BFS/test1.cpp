#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n;
int k;
int u;
int d;

int ans = 0;

int map[9][9] = {};
bool visited[9][9] = {};

vector<pair<int, int>> pos;
bool picked[9][9] = {};

int destX[4] = {1, -1, 0, 0};
int destY[4] = {0, 0, 1, -1};

int BFS(){
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    int cnt = pos.size();

    for(auto& pair : pos){
        q.push(pair);
        visited[pair.second][pair.first] = true;
    }

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];
            int diff = abs(map[cy][cx] - map[ny][nx]);

            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(visited[ny][nx])
                continue;
            if(diff < u || diff > d)
                continue;

            cnt++;
            visited[ny][nx] = true;
            q.emplace(nx, ny);
        }
    }

    return cnt;
}

void select(int x, int y, int cnt){
    if(cnt == k){
        ans = max(ans, BFS());
    }
    else{
        for(int i = y; i < n; i++) {
            for (int j = x; j < n; j++) {
                if(picked[i][x])
                    continue;

                pos.emplace_back(j, i);
                picked[i][j] = true;

                select(j, i, cnt + 1);

                pos.pop_back();
                picked[i][j] = false;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k >> u >> d;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    select(0, 0, 0);
    cout << ans;
}
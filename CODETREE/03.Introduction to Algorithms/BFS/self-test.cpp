#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[101][101] = {};
int visited[101][101] = {};

int destX[4] = {1, -1, 0, 0};
int destY[4] = {0, 0, 1, -1};

int ans = INT_MAX;

struct info{
    int x;
    int y;
    int cnt;
    int dir;
};

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sy >> sx >> ey >> ex;

    queue<info> q;
    q.push({sx, sy, 0, -1});
    memset(visited, -1, sizeof(visited));
    visited[sy][sx] = 0;

    while(!q.empty()){
        int cx = q.front().x;
        int cy = q.front().y;
        int cnt = q.front().cnt;
        int dir = q.front().dir;
        q.pop();

        if(cx == ex && cy == ey){
            ans = min(ans, cnt);
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];
            int nCnt = cnt + (dir != -1 && dir != i);

            if(nx <= 0 || nx > n || ny <= 0 || ny > n)
                continue;
            if(visited[ny][nx] != -1 && visited[ny][nx] < nCnt)
                continue;
            if(map[ny][nx] == 1)
                continue;

            visited[ny][nx] = nCnt;
            q.push({nx, ny, nCnt, i});
        }
    }

    cout << ans;
}
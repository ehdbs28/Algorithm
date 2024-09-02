#include<iostream>
#include<queue>

using namespace std;

int map[502][502] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

int n, m, a, b, k;
pair<int, int> s, e;

bool check(int x, int y){
    if(x < 1 || x + b - 1 > m || y < 1 || y + a - 1 > n)
        return false;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            if(map[y + i][x + j] == 1)
                return false;
        }
    }

    if(map[y][x] == 2)
        return false;

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> a >> b >> k;

    for(int i = 0; i < k; i++){
        int y, x;
        cin >> y >> x;
        map[y][x] = 1;
    }

    cin >> s.second >> s.first >> e.second >> e.first;

    if(map[s.second][s.first] == 1 || map[e.second][e.first] == 1){
        cout << -1;
        return 0;
    }

    queue<pair<pair<int, int>, int>> q;
    q.emplace(s, 0);
    map[s.second][s.first] = 2;

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cd = q.front().second;
        q.pop();

        if(cx == e.first && cy == e.second){
            cout << cd;
            return 0;
        }

        for(int i = 0; i < 4; i++){
            int nx = cx + destX[i];
            int ny = cy + destY[i];
            int nd = cd + 1;

            if(!check(nx, ny))
                continue;

            map[ny][nx] = 2;
            q.push({ { nx, ny }, nd });
        }
    }

    cout << -1;
}
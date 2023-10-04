#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int w;
int h;

char map[1001][1001] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

int cnt = -1;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> w >> h;

        memset(map, 0, sizeof(map));
        queue<pair<int, int>> fireQ;
        queue<pair<pair<int, int>, int>> playerQ;
        int cnt = -1;

        for(int i = 0; i < h; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < w; j++) {
                map[i][j] = line[j];
                if (map[i][j] == '*') {
                    fireQ.push({j, i});
                } else if (map[i][j] == '@') {
                    playerQ.push({{j, i}, 0});
                }
            }
        }

        while(!playerQ.empty()){
            if(cnt > 0)
                break;

            int size = fireQ.size();
            while(size--){
                int cx = fireQ.front().first;
                int cy = fireQ.front().second;
                fireQ.pop();

                for(int i = 0; i < 4; i++){
                    int nx = cx + destX[i];
                    int ny = cy + destY[i];

                    if(nx < 0 || nx >= w || ny < 0 || ny >= h)
                        continue;
                    if(map[ny][nx] == '#')
                        continue;
                    if(map[ny][nx] == '*')
                        continue;

                    map[ny][nx] = '*';
                    fireQ.push({ nx, ny });
                }
            }

            size = playerQ.size();
            while(size--){
                int cx = playerQ.front().first.first;
                int cy = playerQ.front().first.second;
                int cd = playerQ.front().second;
                playerQ.pop();

                if(cx == 0 || cx == w - 1 || cy == 0 || cy == h - 1){
                    cnt = cd + 1;
                    break;
                }

                for(int i = 0; i < 4; i++){
                    int nx = cx + destX[i];
                    int ny = cy + destY[i];

                    if(nx < 0 || nx >= w || ny < 0 || ny >= h)
                        continue;
                    if(map[ny][nx] == '#')
                        continue;
                    if(map[ny][nx] == '*')
                        continue;
                    if(map[ny][nx] == '@')
                        continue;

                    map[ny][nx] = '@';
                    playerQ.push({ { nx, ny }, cd + 1 });
                }
            }
        }

        if(cnt == -1){
            cout << "IMPOSSIBLE" << "\n";
        }
        else{
            cout << cnt << "\n";
        }
    }
}
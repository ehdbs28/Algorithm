#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    char map[1000][1000] = {};
    bool visited[1000][1000] = {};

    int distX[4] = { -1, 1, 0, 0 };
    int distY[4] = { 0, 0, -1, 1 };

    queue<pair<pair<int, int>, int>> pq;
    queue<pair<int, int>> fq;

    int r, c;

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];

            if(map[i][j] == 'J'){
                visited[i][j] = true;
                pq.push({ { j, i }, 0 });
            }

            if(map[i][j] == 'F'){
                visited[i][j] = true;
                fq.emplace(j, i);
            }
        }
    }

    while(!pq.empty()){
        int fsize = fq.size();
        while(fsize > 0){
            int fx = fq.front().first;
            int fy = fq.front().second;
            fq.pop();

            for(int i = 0; i < 4; i++){
                int nx = fx + distX[i];
                int ny = fy + distY[i];

                if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                    continue;
                if(visited[ny][nx])
                    continue;
                if(map[ny][nx] == '#')
                    continue;

                visited[ny][nx] = true;
                fq.emplace(nx, ny);
            }
            --fsize;
        }

        int psize = pq.size();
        while(psize > 0){
            int cx = pq.front().first.first;
            int cy = pq.front().first.second;
            int cd = pq.front().second;
            pq.pop();

            if(cx == 0 || cx == c - 1 || cy == 0 || cy == r - 1){
                cout << cd + 1;
                return 0;
            }

            for(int i = 0; i < 4; i++){
                int nx = cx + distX[i];
                int ny = cy + distY[i];
                int nd = cd + 1;

                if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                    continue;
                if(visited[ny][nx])
                    continue;
                if(map[ny][nx] == '#')
                    continue;

                visited[ny][nx] = true;
                pq.push({ { nx, ny }, nd });
            }
            --psize;
        }
    }

    cout << "IMPOSSIBLE";
}
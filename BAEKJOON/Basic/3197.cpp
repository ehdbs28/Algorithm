#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r;
int c;

char map[1501][1501] = {};
bool check[1501][1501] = {};

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

vector<pair<int, int>> waters;
queue<pair<int, int>> swans;

bool Find = false;

int day = 0;

void BFS(){
    queue<pair<int, int>> temp;

    while(!swans.empty()){
        int x = swans.front().first;
        int y = swans.front().second;
        swans.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + destX[i];
            int ny = y + destY[i];

            if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                continue;

            if(check[ny][nx])
                continue;

            if(map[ny][nx] == 'X'){
                temp.emplace(nx, ny);
                check[ny][nx] = true;
                continue;
            }

            if(map[ny][nx] == 'L'){
                check[ny][nx] = true;
                Find = true;
                break;
            }

            check[ny][nx] = true;
            swans.emplace(nx, ny);
        }
    }

    swans = temp;
}

void WaterCheck(){
    vector<pair<int, int>> temp;
    for(int i = 0; i < waters.size(); i++){
        int x = waters[i].first;
        int y = waters[i].second;

        for(int j = 0; j < 4; j++){
            int nx = x + destX[j];
            int ny = y + destY[j];

            if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                continue;

            if(map[ny][nx] == 'X'){
                map[ny][nx] = '.';
                temp.emplace_back(nx, ny);
            }
        }
    }
    waters = temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];
            if(map[i][j] == 'L'){
                if(swans.empty()){
                    swans.emplace(j, i);
                    check[i][j] = true;
                }
                waters.emplace_back(j, i);
            }
            else if(map[i][j] == '.')
                waters.emplace_back(j, i);
        }
    }

    while(!Find){
        BFS();
        if(!Find){
            WaterCheck();
            ++day;
        }
    }

    cout << day;
}
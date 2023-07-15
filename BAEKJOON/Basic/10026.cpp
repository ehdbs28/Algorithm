#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int n;
vector<string> v;

int destX[4] = { -1, 1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

void BFS(int x, int y, bool isWeekness, bool check[101][101]){
    queue<pair<int, int>> q;
    char target = v[y][x];
    
    q.push({ x, y });
    check[y][x] = true;

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pair<int, int> next = { node.first + destX[i], node.second + destY[i] };

            if(next.first < 0 || next.first > n - 1 || next.second < 0 || next.second > n - 1)
                continue;
            
            if(check[next.second][next.first] == true)
                continue;

            if(v[next.second][next.first] != target && !(isWeekness && target != 'B' && v[next.second][next.first] != 'B'))
                continue;

            check[next.second][next.first] = true;
            q.push(next);
        }
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        v.push_back(line);
    }

    int sector = 0;
    bool check[101][101] = {};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == false){
                BFS(j, i, false, check);
                ++sector;
            }
        }
    }
    cout << sector << " ";

    sector = 0;
    memset(check, false, sizeof(check));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j] == false){
                BFS(j, i, true, check);
                ++sector;
            }
        }
    }
    cout << sector;
}
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int r;
int c;
int t;

int map[51][51] = {};
int add[51][51] = {};

int top_cleaner = -1;
int btm_cleaner = -1;

int dest[2][4] = {
    { 1, 0, -1, 0 },
    { 0, 1, 0, -1 }
};


void Diffusion(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] == 0 || map[i][j] == -1)
                continue;

            int cnt = 0;
            int diffusionValue = map[i][j] / 5;

            for(int k = 0; k < 4; k++){
                int nx = j + dest[0][k];
                int ny = i + dest[1][k];

                if(nx < 0 || nx >= c || ny < 0 || ny >= r)
                    continue;
                if(map[ny][nx] == -1)
                    continue;

                add[ny][nx] += diffusionValue;
                ++cnt;
            }

            add[i][j] -= (diffusionValue * cnt);
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++) {
            map[i][j] += add[i][j];
            add[i][j] = 0;
        }
    }
}

void Cleaning(){
    for (int i = top_cleaner - 1; i > 0; i--)
        map[i][0] = map[i - 1][0];
    for (int i = 0; i < c - 1; i++)
        map[0][i] = map[0][i + 1];
    for (int i = 1; i <= top_cleaner; i++)
        map[i - 1][c - 1] = map[i][c - 1];
    for (int i = c - 1; i > 1; i--)
        map[top_cleaner][i] = map[top_cleaner][i - 1];
    map[top_cleaner][1] = 0;

    for (int i = btm_cleaner + 1; i < r - 1; i++)
        map[i][0] = map[i + 1][0];
    for (int i = 0; i < c - 1; i++)
        map[r - 1][i] = map[r - 1][i + 1];
    for (int i = r - 1; i >= btm_cleaner; i--)
        map[i][c - 1] = map[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--)
        map[btm_cleaner][i] = map[btm_cleaner][i - 1];
    map[btm_cleaner][1] = 0;
}

int TotalDust(){
    int total = 0;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(map[i][j] > 0){
                total += map[i][j];
            }
        }
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c >> t;

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> map[i][j];

            if(map[i][j] < 0){
                if(top_cleaner == -1){
                    top_cleaner = i;
                }
                else{
                    btm_cleaner = i;
                }
            }
        }
    }

    while(t--){
        Diffusion();
        Cleaning();
    }

    cout << TotalDust();
}
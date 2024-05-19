#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int N;
int Distance[51][51];

void reset_distance(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            Distance[i][j] = INF;
        }
    }
}

void floyd_warshall(){
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            for(int k = 1; k <= N; k++)
            {
                if(Distance[j][i] != INF && Distance[i][k] != INF && j != k){
                    Distance[j][k] = min(Distance[j][k], Distance[j][i] + Distance[i][k]);
                }
            }
        }
    }
}

void solve(){
    int ans = 0;
    floyd_warshall();
    for(int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= N; j++)
        {
            if(Distance[i][j] <= 2) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    reset_distance();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            char x;
            cin >> x;
            if(x == 'Y'){
                if(Distance[i][j] > 1) Distance[i][j] = 1;
            }
        }
    }
    solve();
}
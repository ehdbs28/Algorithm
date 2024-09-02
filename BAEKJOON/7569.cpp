#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int destX[6] = { -1, 1, 0, 0, 0, 0 };
int destY[6] = { 0, 0, -1, 1, 0, 0 };

int arr[10001][101] = {};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    int m;
    int h;

    int answer = 0;

    queue<pair<int, int>> q;

    cin >> m >> n >> h;
    destY[4] = -n;
    destY[5] = n;

    for(int i = 0; i < n * h; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push({ j, i });
            }
        }
    }

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 6; i++){
            pair<int, int> next = { node.first + destX[i], node.second + destY[i]};

            if(next.first < 0 || next.first > m - 1 || next.second < 0 || next.second > n * h - 1)
                continue;

            if(i < 4 && node.second / n != next.second / n)
                continue;

            if(arr[next.second][next.first] == -1)
                continue;

            if(arr[next.second][next.first] != 0 && arr[next.second][next.first] <= arr[node.second][node.first] + 1)
                continue;

            arr[next.second][next.first] = arr[node.second][node.first] + 1;
            q.push(next);
        }
    }

    for(int i = 0; i < n * h; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                cout << -1;
                return 0;
            }

            if(arr[i][j] > 0){
                answer = max(answer, arr[i][j]);
            }
        }
    }

    cout << answer - 1;
}
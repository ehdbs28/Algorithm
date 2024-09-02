#include<iostream>

using namespace std;

int map[1025][1025] = {};
long prefix_sum[1025][1025] = {};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (i == 1) {
                prefix_sum[i][j] = prefix_sum[i][j - 1] + map[i][j];
            }
            else if(j == 1){
                prefix_sum[i][j] = prefix_sum[i - 1][j] + map[i][j];
            }
            else {
                prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + map[i][j];
            }
        }
    }

    for(int i = 0; i < m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (prefix_sum[x2][y2] - prefix_sum[x1 - 1][y2] - prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1]) << "\n";
    }
}
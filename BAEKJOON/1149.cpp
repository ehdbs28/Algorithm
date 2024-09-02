#include<iostream>

using namespace std;

int main(){
    int n;

    int cost[1001][3] = {};

    cost[0][0] = 0;
    cost[0][1] = 0;
    cost[0][2] = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int rgb[3] = {};

        cin >> rgb[0] >> rgb[1] >> rgb[2];

        cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + rgb[0];
        cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + rgb[1];
        cost[i][2] = min(cost[i - 1][1], cost[i - 1][0]) + rgb[2];
    }

    cout << min(cost[n][0], min(cost[n][1], cost[n][2]));
}
#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    int m;
    int r;

    int items[101];
    int arr[101][101] = {};

    int ans = 0;

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = INT_MAX;
        }
    }

    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        items[i] = val;
    }

    for(int i = 0; i < r; i++){
        int from, to, val;
        cin >> from >> to >> val;

        if(arr[from][to] > val)
            arr[from][to] = val;

        if(arr[to][from] > val)
            arr[to][from] = val;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(arr[j][i] != INT_MAX && arr[i][k] != INT_MAX)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int temp = 0;
        for(int j = 1; j <= n; j++){
            if(i == j || arr[i][j] <= m)
                temp += items[j];
        }
        ans = max(ans, temp);
    }

    cout << ans;
}
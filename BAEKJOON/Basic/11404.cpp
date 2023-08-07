#include<iostream>
#include<vector>
#include<climits>

using namespace std;

#define INF 10000001

int main(){
    int v;
    int e;

    int arr[101][101] = {};

    cin >> v >> e;

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            arr[i][j] = INF;
        }
    }

    for(int i = 0; i < e; i++){
        int from;
        int to;
        int val;

        cin >> from >> to >> val;

        if(arr[from][to] > val)
            arr[from][to] = val;
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            for(int k = 1; k <= v; k++){
                if(arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }

    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            if(i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
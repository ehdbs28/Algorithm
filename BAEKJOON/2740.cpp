#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a[100][100] = {};
    int b[100][100] = {};
    int c[100][100] = {};

    int n, m, k;

    cin >> n >> m;

    for(int i = 0; i < n * m; i++){
        cin >> a[i / m][i % m];
    }

    cin >> m >> k;

    for(int i = 0; i < m * k; i++){
        cin >> b[i / k][i % k];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            for(int k = 0; k < m; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
}
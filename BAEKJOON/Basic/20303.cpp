#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
int k;

int parent[30001] = {};
int c[30001] = {};
int friends[30001] = {};

int dp[3001] = {};

int find(int x){
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> c[i];
        parent[i] = i;
        friends[i] =1;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    for(int i = 1; i <= n; i++){
        if(parent[i] != i){
            int P = find(i);
            c[P] += c[i];
            friends[P] += friends[i];
        }
    }

    for(int i = 1; i <= n; i++){
        if(parent[i] != i)
            continue;

        for(int j = k - 1; j - friends[i] >= 0; j--){
            dp[j] = max(dp[j], dp[j - friends[i]] + c[i]);
        }
    }

    cout << dp[k - 1];
}
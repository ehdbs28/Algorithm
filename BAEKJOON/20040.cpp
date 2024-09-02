#include<iostream>

using namespace std;

int parent[500001] = {};

int find(int x){
    if(x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

bool isUnion(int x, int y){
    return find(x) == find(y);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    parent[y] = x;
}

int main(){
    int n;
    int m;

    int ans = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int x;
        int y;
        cin >> x >> y;

        if(ans == 0){
            if(isUnion(x, y)){
                ans = i;
            }
            Union(x, y);
        }
    }

    cout << ans;
}
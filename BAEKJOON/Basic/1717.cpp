#include<iostream>

using namespace std;

int parent[1000001] = {};

int find(int x){
    if(parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return;

    parent[y] = x;
}

bool isUnion(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int calc;
        int x;
        int y;

        cin >> calc;

        if(calc == 0){
            cin >> x >> y;
            merge(x, y);
        }
        else{
            cin >> x >> y;
            cout << (isUnion(x, y) ? "YES" : "NO") << "\n";
        }
    }
}
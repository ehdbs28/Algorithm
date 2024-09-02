#include<iostream>

using namespace std;

int parent[100001] = {};

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
    int g;
    int p;

    cin >> g >> p;

    for(int i = 1; i <= g; i++){
        parent[i] = i;
    }

    for(int i = 0; i < p; i++){
        int gi;
        cin >> gi;

        gi = find(gi);

        if(gi == 0){
            cout << i;
            return 0;
        }

        Union(gi - 1, gi);
    }

    cout << p;
}
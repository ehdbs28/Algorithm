#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int len[200001] = {};
int parent[200001] = {};

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

    len[x] += len[y];
    parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int f;
        int idx = 1;

        string x;
        string y;

        unordered_map<string, int> m;

        cin >> f;

        for(int i = 1; i <= f * 2; i++){
            parent[i] = i;
            len[i] = 1;
        }

        for(int i = 0; i < f; i++){
            cin >> x >> y;

            if(m.count(x) == 0)
                m[x] = idx++;

            if(m.count(y) == 0)
                m[y] = idx++;

            merge(m[x], m[y]);

            int _x = find(m[x]);
            int _y = find(m[y]);

            cout << (max(len[_x], len[_y])) << "\n";
        }
    }
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
    int from;
    int to;
    int val;
};

int parent[100001] = {};
vector<Edge> edges;

int n;
int m;

int maxVal = 0;
int ans = 0;

int Find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void merge(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    parent[y] = x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int from;
        int to;
        int val;
        cin >> from >> to >> val;
        edges.push_back({ from, to, val });
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.val < b.val;
    });

    for(int i = 0; i < m; i++){
        Edge e = edges[i];

        if(Find(e.from) == Find(e.to)){
            continue;
        }

        merge(e.from, e.to);

        maxVal = max(maxVal, e.val) ;
        ans += e.val;
    }

    cout << ans - maxVal;
}
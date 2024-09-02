#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
    int from;
    int to;
    int val;
};

int parents[10001] = {};
int vals[10001] = {};
vector<Edge> edges;

int n;
int m;

int minC = 1001;
int ans = 0;

int Find(int x){
    if(parents[x] == x)
        return x;

    return parents[x] = Find(parents[x]);
}

void Merge(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y)
        return;

    parents[y] = x;
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        parents[i] = i;
    }

    for(int i = 1; i <= n; i++){
        int val;
        cin >> val;
        minC = min(minC, val);
        vals[i] = val;
    }

    for(int i = 0; i < m; i++){
        int from, to, val;
        cin >> from >> to >> val;
        edges.push_back({ from, to, val * 2 + vals[to] + vals[from] });
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.val < b.val;
    });

    for(int i = 0; i < m; i++){
        Edge e = edges[i];

        if(Find(e.from) == Find(e.to))
            continue;

        Merge(e.from, e.to);

        ans += e.val;
    };

    cout << ans + minC;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int from;
    int to;
    int val;
};

int n;
int m;
int t;
int p = 0;
int ans = 0;

int parent[10001] = {};
vector<Edge> edges;

int Find(int x)
{
    if(parent[x] == x)
    {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if(x == y)
    {
        return;
    }

    parent[y] = x;
}

int main()
{
    cin >> n >> m >> t;

    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), [](const Edge a, const Edge b){
           return a.val < b.val;
    });

    for(int i = 0; i < m; i++){
        Edge e = edges[i];

        if(Find(e.from) == Find(e.to)){
            continue;
        }

        Union(e.from, e.to);
        ans += e.val + p;
        p += t;
    }

    cout << ans;
}
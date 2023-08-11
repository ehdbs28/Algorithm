#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge{
    int from;
    int to;
    int val;
};

int parents[100001] = {};

vector<pair<int, int>> xVal;
vector<pair<int, int>> yVal;
vector<pair<int, int>> zVal;

vector<Edge> edges;

int n;
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
    cin >> n;

    for(int i = 1; i <= n; i++)
        parents[i] = i;

    for(int i = 1; i <= n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xVal.emplace_back(x, i);
        yVal.emplace_back(y, i);
        zVal.emplace_back(z, i);
    }

    sort(xVal.begin(), xVal.end());
    sort(yVal.begin(), yVal.end());
    sort(zVal.begin(), zVal.end());

    for(int i = 0; i < n - 1; i++){
        edges.push_back({ xVal[i + 1].second, xVal[i].second, xVal[i + 1].first - xVal[i].first });
        edges.push_back({ yVal[i + 1].second, yVal[i].second, yVal[i + 1].first - yVal[i].first });
        edges.push_back({ zVal[i + 1].second, zVal[i].second, zVal[i + 1].first - zVal[i].first });
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
       return a.val < b.val;
    });

    for(int i = 0; i < edges.size(); i++){
        Edge e = edges[i];

        if(Find(e.from) == Find(e.to))
            continue;

        Merge(e.from, e.to);

        ans += e.val;
    }

    cout << ans;
}
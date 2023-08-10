#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct Edge{
    int from;
    int to;
    int val;
};

int parent[10001] = {};
vector<Edge> edges;
vector<pair<int, int>> stars;

int n;

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

    cin >> n;

    for(int i = 1; i <= 10000; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        float x;
        float y;
        int idx;

        cin >> x >> y;

        x *= 100;
        y *= 100;

        stars.emplace_back((int)x, (int)y);

        for(int j = 0; j < i - 1; j++){
            int maxPosX = max(stars[j].first, (int)x);
            int minPosX = min(stars[j].first, (int)x);
            int maxPosY = max(stars[j].second, (int)y);
            int minPosY = min(stars[j].second, (int)y);

            int len = sqrt(pow(maxPosX - minPosX, 2) + pow(maxPosY - minPosY, 2));

            edges.push_back({ i, j + 1, len });
        }

    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.val < b.val;
    });

    for(int i = 0; i < edges.size(); i++){
        Edge e = edges[i];

        if(Find(e.from) == Find(e.to)){
            continue;
        }

        merge(e.from, e.to);

        ans += e.val;
    }

    cout << (float)ans / 100.f;
}
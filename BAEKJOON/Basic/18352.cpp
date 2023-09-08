#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    int k;
    int s;

    int cnt = 0;

    vector<int> graph[300001] = {};
    vector<int> dist;

    cin >> n >> m >> k >> s;

    dist.resize(n + 1, INT_MAX);

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[s] = 0;
    pq.emplace(0, s);

    while(!pq.empty()){
        pair<int, int> cur = pq.top();
        pq.pop();

        for(int i = 0; i < graph[cur.second].size(); i++){
            int next = graph[cur.second][i];
            int nd = cur.first + 1;

            if(nd < dist[next]){
                dist[next] = nd;
                pq.emplace(nd, next);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] == k){
            ++cnt;
            cout << i << "\n";
        }
    }

    if(cnt == 0){
        cout << -1;
    }
}
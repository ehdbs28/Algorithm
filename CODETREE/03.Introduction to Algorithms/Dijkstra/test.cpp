#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX (int)1e8

vector<pair<int, int>> v[100001] = {};
int ans = 0;

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from, to, dis;
        cin >> from >> to >> dis;
        v[from].emplace_back(to, dis);
        v[to].emplace_back(from, dis);
    }

    vector<int> dist(n, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[n] = 0;
    pq.emplace(0, n);

    while(!pq.empty()){
        int cDis = pq.top().first;
        int cIdx = pq.top().second;
        pq.pop();

        for(int j = 0; j < v[cIdx].size(); j++){
            int nIdx = v[cIdx][j].first;
            int nDis = cDis + v[cIdx][j].second;

            if(nDis < dist[nIdx]){
                dist[nIdx] = nDis;
                pq.emplace(nDis, nIdx);
            }
        }
    }

    for(int i = 1; i < n; i++){
        ans = max(ans, dist[i]);
    }

    cout << ans;
}
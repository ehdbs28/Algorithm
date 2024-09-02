#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    int m;

    vector<pair<int, int>> v[1001];

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from;
        int to;
        int dis;

        cin >> from >> to >> dis;

        v[from].emplace_back(to, dis);
    }

    int sv;
    int ev;

    cin >> sv >> ev;

    int check[1001] = {};
    fill(check, check + 1001, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.emplace(0, sv);
    check[sv] = 0;

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(cur.second == ev){
            cout << cur.first;
            return 0;
        }

        for(int i = 0; i < v[cur.second].size(); i++){
            auto next = v[cur.second][i];

            if(cur.first + next.second < check[next.first]){
                check[next.first] = cur.first + next.second;
                pq.emplace(cur.first + next.second, next.first);
            }
        }
    }
}
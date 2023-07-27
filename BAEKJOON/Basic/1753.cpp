#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

    vector<pair<int, int>> graph[20001] = {};
    vector<int> check;

    int v;
    int e;
    int s;

    cin >> v >> e >> s;

    check = vector<int>(v, INT_MAX);

    for(int i = 0; i < e; i++){
        int v1, v2, dis;
        cin >> v1 >> v2 >> dis;
        graph[v1].emplace_back(v2, dis);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, s);
    check[s - 1] = 0;

    while(!pq.empty()){
        pair<int, int> node = pq.top();
        pq.pop();

        for(int i = 0; i < graph[node.second].size(); i++){
            pair<int, int> next = graph[node.second][i];

            if(node.first + next.second < check[next.first - 1]){
                check[next.first - 1] = node.first + next.second;
                pq.emplace(node.first + next.second, next.first);
            }
        }
    }

    for(int i = 0; i < v; i++){
        if(check[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << check[i] << "\n";
    }
}
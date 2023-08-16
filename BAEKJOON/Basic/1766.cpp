#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n, m;

    int indegree[32001] = {};
    vector<int> graph[32001] = {};

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        indegree[to]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();

        cout << cur << " ";

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];

            indegree[next]--;
            if(indegree[next] == 0)
                pq.push(next);
        }
    }
}
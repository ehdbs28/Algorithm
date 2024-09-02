#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<int> *graph, int start, bool *check){
    queue<int> q;

    q.push(start);
    check[start] = true;

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i];

            if(check[next] == true)
                continue;

            check[next] = true;
            q.push(next);
        }
    }
}

int main(){
    vector<int> graph[1001] = {};
    bool check[1001] = {};
    
    int n;
    int m;

    int answer = 0;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int cur;
        int next;
        cin >> cur >> next;
        graph[cur].push_back(next);
        graph[next].push_back(cur);
    }

    for(int i = 1; i <= n; i++){
        if(check[i] == true)
            continue;
        
        bfs(graph, i, check);
        ++answer;
    }

    cout << answer;
}
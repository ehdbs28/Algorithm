#include<iostream>
#include<vector>

using namespace std;

int answer = 0;

void dfs(vector<int> *graph, int v, bool *visited){
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++){
        int next = graph[v][i];

        if(visited[next] == false){
            ++answer;
            dfs(graph, next, visited);
        }
    }
}

int main(){
    vector<int> graph[101] = {};
    bool visited[101] = {};

    int n;
    int m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int cur;
        int next;

        cin >> cur >> next;

        graph[cur].push_back(next);
        graph[next].push_back(cur);
    }

    dfs(graph, 1, visited);

    cout << answer;
}
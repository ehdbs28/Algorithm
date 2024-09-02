#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[100001] = {};
int visited[100001] = {};

int main(){
    int n, m, r;
    int visitedNum = 1;

    cin >> n >> m >> r;

    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }

    queue<int> q;
    q.push(r);
    visited[r] = visitedNum++;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(visited[next] == 0){
                visited[next] = visitedNum++;
                q.push(next);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << visited[i] << "\n";
    }
}
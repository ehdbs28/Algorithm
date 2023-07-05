#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

void DFS(int graph[1001][1001], bool *check, int v){
    cout << v << " ";
    check[v] = true;

    for(int i = 0; i < 1001; i++){
        if(graph[v][i] == 0)
                continue;
        if(check[i] == true)
            continue;

        DFS(graph, check, i);
    }
}

void BFS(int graph[1001][1001], bool *check, int v){
    queue<int> q;

    check[v] = true;
    q.push(v);

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i = 0; i < 1001; i++){
            if(graph[node][i] == 0)
                continue;
            if(check[i] == true)
                continue;

            check[i] = true;
            q.push(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    int m;
    int v;

    int graph[1001][1001] = {};
    bool check[1001] = {};

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        int start;
        int end;

        cin >> start >> end;

        graph[start][end] = 1;
        graph[end][start] = 1;
    }

    DFS(graph, check, v);

    cout << "\n";
    fill(check, check + 1001, false);
    
    BFS(graph, check, v);
}
#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[32001] = {};
bool check[32001] = {};

void DFS(int n){
    check[n] = true;

    for(int i = 0; i < graph[n].size(); i++){
        if(!check[graph[n][i]])
            DFS(graph[n][i]);
    }

    cout << n << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from;
        int to;
        cin >> from >> to;
        graph[to].push_back(from);
    }

    for(int i = 1; i <= n; i++){
        if(!check[i])
            DFS(i);
    }
}
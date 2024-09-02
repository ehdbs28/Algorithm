#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int n, m;

vector<pair<int, int>> v[1001] = {};
bool visited[1001] = {};

void DFS(int i, int e, int val){
    visited[i] = true;

    if(i == e){
        cout << val << "\n";
        return;
    }

    for(int j = 0; j < v[i].size(); j++){
        pair<int, int> node = v[i][j];

        if(!visited[node.first]){
            DFS(node.first, e, val + node.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < n - 1; i++){
        int from, to, val;
        cin >> from >> to >> val;
        v[from].emplace_back(to, val);
        v[to].emplace_back(from, val);
    }

    for(int i = 0; i < m; i++){
        memset(visited, false, sizeof(visited));
        int s, e;
        cin >> s >> e;
        DFS(s, e, 0);
    }
}
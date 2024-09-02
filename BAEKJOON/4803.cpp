#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int vertex;
int edge;
bool visited[501] = {};
vector<int> graph[501] = {};

void DFS(int n){
    visited[n] = true;

    vertex++;
    edge += graph[n].size();

    for(int i = 0; i < graph[n].size(); i++){
        if(!visited[graph[n][i]]){
            DFS(graph[n][i]);
        }
    }
}

int main(){
    int c = 0;
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;

        ++c;

        for(int i = 0; i <= n; i++)
            graph[i].clear();
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int tree = 0;

        for(int i = 1; i <= n; i++){
            if(visited[i])
                continue;

            vertex = 0;
            edge = 0;

            DFS(i);

            if(edge == (vertex - 1) * 2)
                tree++;
        }

        cout << "Case " << c << ": ";
        if(tree == 0){
            cout << "No trees." << "\n";
        }
        else if(tree == 1){
            cout << "There is one tree." << "\n";
        }
        else{
            cout << "A forest of " << tree << " trees." << "\n";
        }
    }
}
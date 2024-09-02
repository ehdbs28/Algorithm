#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 0;

vector<int> graph[101] = {};
int visited[101] = {};

void DFS(int v){
    for(int i = 0; i < graph[v].size(); i++){
        int next = graph[v][i];
        if(visited[next] == 0){
            visited[next] = 1;
            DFS(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            if(num == 1){
                graph[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        fill(visited, visited + 101, 0);
        DFS(i);   
        for(int j = 0; j < n; j++){
            cout << visited[j] << " ";
        }
        cout << "\n";
    }
}
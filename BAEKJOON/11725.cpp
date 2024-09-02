#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> graph[100001] = {};
bool check[100001] = {};
int answer[100001] = {};

void DFS(int node){
    check[node] = true;

    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];

        if(!check[next]){
            answer[next] = node;
            DFS(next);
        }
    }
}

int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        int from;
        int to;

        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    DFS(1);

    for(int i = 2; i <= n; i++){
        cout << answer[i] << "\n";
    }
}

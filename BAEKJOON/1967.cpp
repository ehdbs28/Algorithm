#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[100001] = {};
bool check[100001] = {};

int start = 0;
int answer = 0;

void dfs(int node, int dis){
    check[node] = true;

    if(answer < dis){
        answer = dis;
        start = node;
    }

    for(auto & i : v[node]){
        if(check[i.first])
            continue;

        dfs(i.first, dis + i.second);
    }
}

int main(){
    int n = 0;

    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int vertex;
        int next;
        int dis;

        cin >> vertex >> next >> dis;

        v[vertex].emplace_back( next, dis );
        v[next].emplace_back(vertex, dis);
    }

    dfs(1, 0);
    answer = 0;
    memset(check, false, sizeof(check));
    dfs(start, 0);

    cout << answer;
}
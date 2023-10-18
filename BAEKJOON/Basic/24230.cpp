#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> v[200001] = {};
int dest[200001] = {};

int ans = 0;

int DFS(int node, int prev){
    int cnt = 0;

    for(int i = 0; i < v[node].size(); i++){
        int next = v[node][i];
        if(next == prev)
            continue;
        cnt += DFS(next, node) + (dest[node] != dest[next]);
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> dest[i];
    }

    for(int i = 1; i < n; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    ans = DFS(1, 0);
    if(dest[1] != 0){
        ans++;
    }

    cout << ans;
}
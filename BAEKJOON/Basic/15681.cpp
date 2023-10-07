#include<vector>
#include<iostream>

using namespace std;

int n;
int r;
int q;

vector<int> tree[100001];
bool visited[100001];
int dp[100001];

int DFS(int node){
    if(dp[node] != 0)
        return dp[node];

    visited[node] = true;
    int temp = 1;

    for(int i = 0; i < tree[node].size(); i++){
        int next = tree[node][i];

        if(!visited[next]){
            temp += DFS(next);
        }
    }

    dp[node] = temp;
    return temp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r >> q;

    for(int i = 1; i < n; i++){
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    dp[r] = DFS(r);

    for(int i = 0; i < q; i++){
        int query;
        cin >> query;
        cout << dp[query] << "\n";
    }
}
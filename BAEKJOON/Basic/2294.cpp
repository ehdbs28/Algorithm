#include<iostream>
#include<set>
#include<queue>
#include<climits>

using namespace std;

int main(){
    int n, k;
    int ans = INT_MAX;

    cin >> n >> k;

    set<int> coins;
    for(int i = 0; i < n; i++){
        int c = 0;
        cin >> c;
        coins.insert(c);
    }

    queue<pair<int, int>> q;
    bool visited[10001] = {};
    q.emplace(0, 0);
    visited[0] = true;

    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == k){
            ans = min(ans, cnt);
        }

        for(int c : coins){
            int dest = cur + c;

            if(dest > k || visited[dest]){
                continue;
            }

            q.emplace(dest, cnt + 1);
            visited[dest] = true;
        }
    }

    cout << (ans == INT_MAX ? -1 : ans);
}
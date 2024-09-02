#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    vector<int> v[1001] = {};
    vector<int> ans;
    int indegree[1001] = {};

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int cnt;
        int last = -1;

        cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int num;
            cin >> num;

            if (last == -1){
                last = num;
                continue;
            }

            v[last].push_back(num);
            indegree[num]++;
            last = num;
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        ans.push_back(cur);

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];

            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }

    if(ans.size() == n){
        for(int i = 0; i < n; i++){
            cout << ans[i] << "\n";
        }
    }
    else{
        cout << 0;
    }
}
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;

        vector<int> v[1001] = {};
        int indegree[1001] = {};
        int delay[1001] = {};
        int result[1001] = {};

        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            cin >> delay[i];
            result[i] = delay[i];
        }

        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            v[from].push_back(to);
            indegree[to]++;
        }

        int k;
        cin >> k;

        queue<int> q;

        for(int i = 1; i <= n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < v[cur].size(); i++){
                int nIdx = v[cur][i];

                result[nIdx] = max(result[nIdx], result[cur] + delay[nIdx]);

                if(--indegree[nIdx] == 0){
                    q.push(nIdx);
                }
            }
        }

        cout << result[k] << "\n";
    }
}
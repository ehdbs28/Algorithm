#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<climits>

using namespace std;

int main(){
    int n;

    vector<int> v[51] = {};
    bool visited[51] = {};
    int score[51] = {};
    int answer = INT_MAX;

    cin >> n;

    while(true){
        int a, b;
        cin >> a >> b;

        if(a == -1 && b == -1)
            break;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;

        int temp = 0;

        q.emplace(i, 1);
        visited[i] = true;

        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();

            for(int j = 0; j < v[node.first].size(); j++){
                int next = v[node.first][j];

                if(!visited[next]){
                    visited[next] = true;
                    q.emplace(next, node.second + 1);
                    temp++;
                }
            }

            if(temp == n - 1){
                answer = min(answer, node.second);
                score[i] = node.second;
                break;
            }
        }
    }

    cout << answer << " ";

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(score[i] == answer)
            cnt++;
    }

    cout << cnt << "\n";

    for(int i = 1; i <= n; i++){
        if(score[i] == answer)
            cout << i << " ";
    }
}

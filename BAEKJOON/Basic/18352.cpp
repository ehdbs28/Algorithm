#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> graph[300001] = {};
vector<int> answer;
bool check[300001] = {};

int main(){

    int v;
    int e;
    int k;

    int start;

    cin >> v >> e >> k >> start;

    for(int i = 0; i < e; i++){
        int from;
        int to;

        cin >> from >> to;

        graph[from].push_back(to);
    }

    queue<pair<int, int>> q;
    q.emplace(start, 0);
    check[start] = true;

    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();

        if(cur.second == k){
            answer.push_back(cur.first);
        }

        for(int i = 0; i < graph[cur.first].size(); i++){
            int next = graph[cur.first][i];

            if(check[next])
                continue;

            check[next] = true;
            q.emplace(next, cur.second + 1);
        }
    }

    if(answer.empty()){
        cout << -1;
    }
    else{
        sort(answer.begin(), answer.end(), less<>());

        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << "\n";
        }
    }
}
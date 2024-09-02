#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
int m;

pair<int, int> answer = { -1, -1 };

vector<int> v[101] = {};

int BFS(int start){
    queue<int> q;
    int check[101] = {};

    q.push(start);
    check[start] = 1;

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        for(int i = 0; i < v[node].size(); i++){
            int next = v[node][i];

            if(check[next] > 0)
                continue;

            check[next] = check[node] + 1;
            q.push(next);
        } 
    }

    int value = 0;
    for(int i = 1; i <= n; i++){
        if(check[i] != 0)
            value += check[i] - 1;
    }

    return value;
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int start;
        int end;

        cin >> start >> end;

        v[start].push_back(end);
        v[end].push_back(start);
    }

    for(int i = 1; i <= n; i++){
        int bfs = BFS(i);
        if(answer.first == -1 || answer.second > bfs){
            answer.first = i;
            answer.second = bfs;
        }
    }

    cout << answer.first;
}
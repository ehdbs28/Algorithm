#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool checkNum(vector<bool> &check, int &output){
    for(int i = 1; i < check.size(); i++){
        if(check[i] == false){
            output = i;
            return false;
        }
    }

    return true;
}

int main(){
    vector<int> *graph;
    vector<bool> check;
    
    int n;
    int m;

    int answer = 0;

    cin >> n >> m;
    graph = new vector<int>[n + 1];
    check = vector<bool>(n + 1, false);

    for(int i = 0; i < m; i++){
        int cur;
        int next;
        cin >> cur >> next;
        graph[cur].push_back(next);
        graph[next].push_back(cur);
    }

    int output;
    while(checkNum(check, output) == false){
        queue<int> q;

        q.push(output);
        check[output] = true;

        while(q.empty() == false){
            int node = q.front();
            q.pop();

            for(int i = 0; i < graph[node].size(); i++){
                int next = graph[node][i];

                if(check[next] == true)
                    continue;

                check[next] = true;
                q.push(next);
            }
        }

        ++answer;
    }

    cout << answer;
}
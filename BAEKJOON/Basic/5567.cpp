#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    int m;

    int answer = 0;

    vector<vector<int>> list;
    vector<int> check;
    queue<int> q;

    cin >> n >> m;
    list.resize(n + 1);
    check = vector<int>(n + 1, -1);

    for(int i = 0; i < m; i++){
        int cur;
        int next;

        cin >> cur >> next;

        list[cur].push_back(next);
        list[next].push_back(cur);
    }

    q.push(1);

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        for(int i = 0; i < list[node].size(); i++){
            int next = list[node][i];

            if(next != 1 && check[next] == -1 && check[node] < 1){
                ++answer;
                check[next] = check[node] + 1;
                q.push(next);
            }
        }
    }

    cout << answer;
}
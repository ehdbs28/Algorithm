#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int m;
int x;

int answer = 0;
int temp = 0;

vector<pair<int, int>> v[1001] = {};
int check[1001] = {};

void dijkstra(int sv, int target){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    fill(check, check + n + 1, INT_MAX);

    pq.emplace(0, sv);
    check[sv] = 0;

    while (!pq.empty()){
        int cur_i = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();

        if(cur_i == target){
            break;
        }

        for(int i = 0; i < v[cur_i].size(); i++){
            int next_i = v[cur_i][i].first;
            int next_cost = cur_cost + v[cur_i][i].second;

            if(next_cost < check[next_i]){
                check[next_i] = next_cost;
                pq.emplace(next_cost, next_i);
            }
        }
    }

    temp += check[target];
    if(sv != x){
        dijkstra(x, sv);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> x;

    for(int i = 0; i < m; i++){
        int from;
        int to;
        int cost;

        cin >> from >> to >> cost;

        v[from].emplace_back(to, cost);
    }

    for(int i = 1; i <= n; i++){
        if(x == i)
            continue;

        temp = 0;
        dijkstra(i, x);
        answer = max(answer, temp);
    }

    cout << answer;
}
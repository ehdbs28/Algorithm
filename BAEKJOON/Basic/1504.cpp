#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321

using namespace std;

struct node{
    int x;
    int weight;

    bool operator()(node a, node b){
        return a.weight < b.weight;
    }
};

int n;
int e;
int v1;
int v2;

vector<node> v[801] = {};
vector<int> dist;

void dijk(int s){
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
    }

    priority_queue<node, vector<node>, node> pq;
    dist[s] = 0;
    pq.push({ s, 0 });

    while(!pq.empty()){
        node cur = pq.top();
        pq.pop();

        for(int i = 0; i < v[cur.x].size(); i++){
            node next = v[cur.x][i];
            next.weight += cur.weight;

            if(next.weight < dist[next.x]){
                dist[next.x] = next.weight;
                pq.push(next);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> e;
    dist.resize(n + 1, INF);
    for(int i = 0; i < e; i++){
        int from, to, weight;
        cin >> from >> to >> weight;
        v[from].push_back({ to, weight });
        v[to].push_back({ from, weight });
    }
    cin >> v1 >> v2;

    dijk(1);
    int sToV1 = dist[v1];
    int sToV2 = dist[v2];
    dijk(v1);
    int v1ToN = dist[n];
    int v1ToV2 = dist[v2];
    dijk(v2);
    int v2ToN = dist[n];

    int ans = min(INF, min(sToV1 + v1ToV2 + v2ToN, sToV2 + v1ToV2 + v1ToN));

    if(v1ToV2 == INF || ans == INF)
        cout << -1;
    else
       cout << ans;
}
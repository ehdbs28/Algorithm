#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;

class val{
public:
    val(int dis, int idx, vector<int> vt){
        this->dis = dis;
        this->idx = idx;
        this->vt = vector<int>();
        for(int i = 0; i < vt.size(); i++){
            this->vt.push_back(vt[i]);
        }
    }

public:
    int dis;
    int idx;
    vector<int> vt;
};

struct comp{
    bool operator()(val& a, val& b){
        return a.dis > b.dis;
    }
};

int main(){
    vector<pair<int, int>> v[1001] = {};
    int check[1001] = {};

    int n;
    int m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int from;
        int to;
        int cost;

        cin >> from >> to >> cost;

        v[from].emplace_back(to, cost);
    }

    int sv;
    int ev;

    cin >> sv >> ev;

    priority_queue<val, vector<val>, comp> pq;
    val start(0, sv, vector<int>());
    pq.push(start);
    check[sv] = 0;

    fill(check, check + 1001, INT_MAX);

    while(!pq.empty()){
        val node = pq.top();
        pq.pop();

        if(node.idx == ev){
            cout << node.dis << "\n";
            cout << node.vt.size() + 1 << "\n";
            for(int i = 0; i < node.vt.size(); i++){
                cout << node.vt[i] << " ";
            }
            cout << ev;
            break;
        }

        for(int i = 0; i < v[node.idx].size(); i++){
            val next(v[node.idx][i].second + node.dis, v[node.idx][i].first, node.vt);

            if(next.dis < check[next.idx]){
                check[next.idx] = next.dis;
                next.vt.push_back(node.idx);
                pq.emplace(next);
            }
        }
    }
}
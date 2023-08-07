#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Edge{
public:
    Edge(int s, int e, int v){
        start = s;
        end = e;
        val = v;
    }

public:
    int start;
    int end;
    int val;
};

int main(){
    vector<Edge> edges;
    long long D[501] = {};

    int v;
    int e;

    bool minusLoop = false;

    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int from;
        int to;
        int val;
        cin >> from >> to >> val;
        edges.push_back({from, to, val});
    }

    fill(D, D + 501, LONG_LONG_MAX);
    D[1] = 0;

    for(int i = 0; i < v - 1; i++){
        for(int j = 0; j < edges.size(); j++){
            Edge edge = edges[j];

            if(D[edge.start] != LONG_LONG_MAX && D[edge.end] > D[edge.start] + edge.val){
                D[edge.end] = D[edge.start] + edge.val;
            }
        }
    }

    for(int j = 0; j < edges.size(); j++){
        Edge edge = edges[j];

        if(D[edge.start] != LONG_LONG_MAX && D[edge.end] > D[edge.start] + edge.val){
            minusLoop = true;
        }
    }

    if(minusLoop){
        cout << -1;
    }
    else{
        for(int i = 2; i <= v; i++){
            cout << (D[i] == LONG_LONG_MAX ? -1 : D[i]) << "\n";
        }
    }
}
#include<iostream>
#include<vector>

using namespace std;

#define MAX 2000000000

class Edge{
public:
    Edge(int start, int end, int val){
        this->start = start;
        this->end = end;
        this->val = val;
    }

public:
    int start;
    int end;
    int val;

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    while(t--){
        int n;
        int m;
        int w;

        bool loop = false;

        vector<Edge> edges;
        int check[501] = {};

        cin >> n >> m >> w;

        for(int i = 1; i <= n; i++)
            check[i] = MAX;

        for(int i = 0; i < m; i++){
            int start;
            int end;
            int val;
            cin >> start >> end >> val;
            edges.emplace_back(start, end, val);
            edges.emplace_back(end, start, val);
        }

        for(int i = 0; i < w; i++){
            int start;
            int end;
            int val;
            cin >> start >> end >> val;
            edges.emplace_back(start, end, -val);
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < edges.size(); j++){
                Edge e = edges[j];

                if(check[e.end] > check[e.start] + e.val){
                    check[e.end] = check[e.start] + e.val;
                }
            }
        }

        for(int j = 0; j < edges.size(); j++){
            Edge e = edges[j];

            if(check[e.end] > check[e.start] + e.val){
                loop = true;
                break;
            }
        }

        cout << (loop ? "YES" : "NO") << "\n";
    }
}
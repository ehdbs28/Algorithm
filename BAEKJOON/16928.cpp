#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> v[101] = {};
    int check[101] = {};

    int n;
    int m;

    cin >> n >> m;

    for(int i = 0; i < n + m; i++){
        int start;
        int end;
        cin >> start >> end;
        v[start].push_back(end);
    }

    queue<int> q;
    q.push(1);

    while(q.empty() == false){
        int node = q.front();
        q.pop();

        for(int i = 1; i <= 6; i++){
            int next = node + i;

            if(next > 100)
                break;

            if(v[next].empty() == false){
                next = v[next].back();
            }

            if(check[next] > 0)
                continue;

            check[next] = check[node] + 1;
            q.push(next);
        }
    }

    cout << check[100];
}
#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
int k;

int parent[51] = {};

vector<int> know;
vector<vector<int>> v(50);

int Find(int x){
    if(parent[x] == x)
        return x;
    return x = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int t;
        cin >> t;
        know.push_back(t);
    }

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int p;
        int prev;
        int num;

        cin >> p;

        for(int j = 0; j < p; j++){
            cin >> num;

            if(j > 0){
                Union(prev, num);
            }

            prev = num;
            v[i].push_back(num);
        }
    }

    for (auto& list : v) {
        bool flag = false;
        for (auto& person : list) {
            if (flag)
                break;

            for (auto& t : know) {
                if (Find(person) == Find(t)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            m--;
    }

    cout << m;
}
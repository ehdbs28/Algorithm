#include<iostream>

using namespace std;

bool check[9] = {};

int n;
int m;

void DFS(int _n, int cnt){
    if(cnt == m){
        for(int i = 1; i <= n; i++){
            if(check[i])
                cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = _n; i <= n; i++){
        if(!check[i]){
            check[i] = true;
            DFS(i, cnt + 1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    DFS(1, 0);
}
#include<iostream>

using namespace std;

int n;
int m;

int check[9] = {};

void DFS(int num, int cnt){
    if(cnt >= m){
        for(int i = 0; i < m; i++){
            cout << check[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = num; i <= n; i++){
        check[cnt] = i;
        DFS(i, cnt + 1);
        check[cnt] = i;
    }
}

int main(){
    cin >> n >> m;
    DFS(1, 0);
}
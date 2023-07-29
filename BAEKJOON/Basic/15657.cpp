#include<iostream>
#include<algorithm>

using namespace std;

int n;
int m;

int check[9] = {};
int* arr;

void DFS(int num, int cnt){
    if(cnt >= m){
        for(int i = 0; i < m; i++){
            cout << arr[check[i] - 1] << " ";
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
    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, less<>());

    DFS(1, 0);
}
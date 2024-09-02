#include<iostream>
#include<algorithm>

using namespace std;

int n;
int m;

int arr[9] = {};
int check[9] = {};

void DFS(int num, int cnt){
    if(cnt >= m){
        for(int i = 0; i < m; i++){
            cout << arr[check[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int temp = -1;

    for(int i = num; i < n; i++){
        if(arr[i] != temp){
            check[cnt] = i;
            temp = arr[check[cnt]];
            DFS(i, cnt + 1);
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, less<>());

    DFS(0, 0);
}
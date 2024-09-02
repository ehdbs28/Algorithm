#include<iostream>
#include<algorithm>

using namespace std;

int n;
int m;

int arr[9] = {};
int check[9] = {};
bool visited[9] = {};

void DFS(int cnt){
    if(cnt >= m){
        for(int i = 0; i < m; i++){
            cout << arr[check[i]] << " ";
        }
        cout << "\n";
        return;
    }

    int temp = -1;

    for(int i = 0; i < n; i++){
        if(!visited[i] && arr[i] != temp){
            check[cnt] = i;
            temp = arr[check[cnt]];
            visited[i] = true;
            DFS(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, less<>());

    DFS(0);
}
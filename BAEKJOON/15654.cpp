#include<iostream>
#include<algorithm>

using namespace std;

int n;
int m;

int check[9] = {};
bool visited[9] = {};
int* arr;

void DFS(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[check[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(visited[i] == false){
            check[cnt] = i;
            visited[i] = true;
            DFS(num + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    arr = new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n, less<>());

    DFS(0, 0);
}
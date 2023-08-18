#include<iostream>
#include<algorithm>

using namespace std;

int n;

int arr[100001] = {};
bool visited[100001] = {};
bool hasTeam[100001] = {};

int cnt = 0;

void DFS(int num){
    visited[num] = true;
    int next = arr[num];

    if(!visited[next]){
        DFS(next);
    }
    else if(!hasTeam[next]){
        for(int i = next; i != num; i = arr[i]){
            cnt++;
        }
        cnt++;
    }
    hasTeam[num] = true;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;

        cnt = 0;
        fill(visited, visited + n + 1, false);
        fill(hasTeam, hasTeam + n + 1, false);

        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i])
                DFS(i);
        }

        cout << (n - cnt) << "\n";
    }
}
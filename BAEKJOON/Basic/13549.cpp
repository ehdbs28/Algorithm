#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int main(){
    int n;
    int k;

    int check[100001] = {};
    memset(check, -1, sizeof(check));

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    check[n] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == k){
            cout << check[k];
            return 0;
        }

        int next = cur + 1;
        if(next <= k && !(check[next] != -1 && check[next] <= check[cur] + 1)){
            check[next] = check[cur] + 1;
            q.push(next);
        }

        next = cur - 1;
        if(next >= 0 && !(check[next] != -1 && check[next] <= check[cur] + 1)){
            check[next] = check[cur] + 1;
            q.push(next);
        }

        next = cur * 2;
        if(next < 100001 && !(check[next] != -1 && check[next] <= check[cur])){
            check[next] = check[cur];
            q.push(next);
        }
    }
}
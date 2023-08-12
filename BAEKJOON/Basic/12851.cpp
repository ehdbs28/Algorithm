#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int check[100001] = {};

bool able(int n, int cnt){
    if(n < 0 || n > 100000)
        return false;

    if(check[n] == -1)
        return true;

    if(check[n] >= cnt)
        return true;

    return false;
}

int main(){
    int n;
    int k;

    int t;
    int cnt = 0;

    fill(check, check + 100001, -1);

    cin >> n >> k;

    queue<pair<int, int>> q;
    q.emplace(n, 0);
    check[n] = 0;

    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();

        if(node.first == k){
            cnt++;
            t = node.second;
            continue;
        }

        int next = node.first - 1;
        if(able(next, node.second + 1)){
            check[next] = node.second + 1;
            q.emplace(next, node.second + 1);
        }

        next = node.first + 1;
        if(able(next, node.second + 1)){
            check[next] = node.second + 1;
            q.emplace(next, node.second + 1);
        }

        next = node.first * 2;
        if(able(next, node.second + 1)){
            check[next] = node.second + 1;
            q.emplace(next, node.second + 1);
        }
    }

    cout << t << "\n" << cnt;
}
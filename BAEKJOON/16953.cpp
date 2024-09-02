#include<iostream>
#include<queue>

using namespace std;

int main(){
    long long a;
    long long b;

    queue<pair<long long, long long>> q;

    cin >> a >> b;

    q.emplace(a, 1);

    while(!q.empty()){
        pair<long long, long long> cur = q.front();
        q.pop();

        if(cur.first == b){
            cout << cur.second;
            return 0;
        }

        if(cur.first > b){
            continue;
        }

        long long next = cur.first * 2;
        if(next <= b)
            q.emplace(next, cur.second + 1);

        next = cur.first * 10 + 1;
        if(next <= b)
            q.emplace(next, cur.second + 1);
    }

    cout << -1;
}
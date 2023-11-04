#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    int vote;
    int ans = 0;

    priority_queue<int> pq;

    cin >> n;
    cin >> vote;

    for(int i = 1; i < n; i++){
        int v;
        cin >> v;
        pq.push(v);
    }

    while(!pq.empty() && vote + ans <= pq.top()){
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
        ans++;
    }

    cout << ans;
}
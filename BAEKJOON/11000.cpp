#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    int ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> rooms;

    cin >> n;

    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        pq.emplace(s, e);
    }

    while(!pq.empty()){
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();

        if(!rooms.empty() && rooms.top().first <= s){
            rooms.pop();
            rooms.emplace(e, s);
        }
        else{
            ans++;
            rooms.emplace(e, s);
        }
    }

    cout << ans;
}
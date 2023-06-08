#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int, int>> beers;
    priority_queue<int, vector<int>, greater<int>> pq;

    int n, m, k;
    int sum = 0;

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        int v, c;
        cin >> v >> c;
        beers.push_back({v, c});
    }

    sort(beers.begin(), beers.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    for(auto beer : beers){
        pq.push(beer.first);
        sum += beer.first;

        if(pq.size() > n){
            sum -= pq.top();
            pq.pop();
        }

        if(pq.size() == n && sum >= m){
            cout << beer.second;
            return 0;
        }
    }

    cout << -1;
}
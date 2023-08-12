#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int k;

    long long ans = 0;

    pair<long long, long long> zems[300001];
    long long bags[300001];

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        long long weight;
        long long price;

        cin >> weight >> price;

        zems[i] = { weight, price };
    }

    for(int i = 0; i < k; i++){
        cin >> bags[i];
    }

    sort(bags, bags + k);
    sort(zems, zems + n);

    priority_queue<long long> pq;
    int idx = 0;

    for(int i = 0; i < k; i++){
        long long bag = bags[i];

        while(idx < n && zems[idx].first <= bag){
            pq.push(zems[idx].second);
            ++idx;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}
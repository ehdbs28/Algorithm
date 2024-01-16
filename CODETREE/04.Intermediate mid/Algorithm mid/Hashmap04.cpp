#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;
    unordered_map<long long, int> m;

    int n;
    int k;

    int ans = 0;

    cin >> n >> k;
    v.resize(n, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        long long diff = (long long)k - v[i];
        ans += m[diff];
        m[v[i]]++;
    }

    cout << ans;
}
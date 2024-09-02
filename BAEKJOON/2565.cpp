#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    int cnt = 0;

    int dp[501] = {};
    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        int left;
        int right;
        cin >> left >> right;
        v.emplace_back(left, right);
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[j].second < v[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        if(dp[i] == 0)
            dp[i] = 1;

        cnt = max(cnt, dp[i]);
    }

    cout << n - cnt;
}
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int main(){
    vector<pair<int, int>> v;
    int n;
    int ans = INT_MAX;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }

    for (int i = 1; i < (1 << n); i++){
        int a = 1;
        int b = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                a *= v[j].first;
                b += v[j].second;
            }
        }
        ans = min(ans, abs(a - b));
    }

    cout << ans;
}
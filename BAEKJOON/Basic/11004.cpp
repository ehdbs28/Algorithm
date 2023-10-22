#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v;

    int n;
    int k;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end(), less<>());

    cout << v[k - 1];
}
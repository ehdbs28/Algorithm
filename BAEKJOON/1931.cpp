#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    int cur = 0;
    int answer = 0;

    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        int start;
        int end;

        cin >> start >> end;
        v.emplace_back(start, end);
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        } 
        return a.second < b.second; 
    });

    for(int i = 0; i < n; i++){
        if(v[i].first < cur)
            continue;

        cur = v[i].second;
        ++answer;
    }

    cout << answer;
}

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    
    vector<int> v;
    vector<pair<int, int>> s;

    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
        s.push_back({ input, i });
    }

    sort(s.begin(), s.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    });

    int x = 0;
    int last = s[0].first;
    for(int i = 0; i < n; i++){
        if(s[i].first != last){
            ++x;
            last = s[i].first;
        }
        v[s[i].second] = x;
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}
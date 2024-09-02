#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;

    int max_value = 0;
    int answer = 0;

    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        int p;
        int d;

        cin >> p >> d;

        v.push_back({ p, d });
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        int price = v[i].first;
        int cur = 0;

        for(int j = 0; j < n; j++){
            if(v[j].first >= price){
                int temp = price - v[j].second;

                if(temp > 0)
                    cur += temp;
            }    
        }

        if(max_value < cur){
            answer = price;
            max_value = cur;
        }
    }

    cout << answer;
}
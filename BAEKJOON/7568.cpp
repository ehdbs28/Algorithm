#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<pair<int, int>> peoples;

    int cnt, weight, height, count = 0;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        cin >> weight >> height;
        peoples.push_back({ weight, height });
    }

    for(int i = 0; i < cnt; i++){
        count = 0;
        for(int j = 0; j < cnt; j++){
            if(i == j) continue;

            if(peoples[i].first < peoples[j].first && peoples[i].second < peoples[j].second){
                ++count;
            }
        }
        cout << 1 + count << " ";
    }
}
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> map;
    int n;
    long long ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        if(map.find(x) == map.end()){
            map.insert({ x, y });
            ans += y;
        }
        else{
            if(map[x] > y){
                ans -= map[x];
                map[x] = y;
                ans += y;
            }
        }
    }

    cout << ans;
}
#include<iostream>
#include<map>

using namespace std;

int main(){
    int n;
    int m;

    int answer = 0;

    map<int, int> set;

    cin >> n >> m;

    for(int i = 0; i < n + m; i++){
        int input;
        cin >> input;
        ++set[input];
    }

    for(auto pair : set){
        if(pair.second == 1){
            ++answer;
        }
    }

    cout << answer;
}
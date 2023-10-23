#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int solution(vector<vector<string>> clothes){
    map<string, int> m;

    for(auto& cloth : clothes){
        m[cloth[1]]++;
    }

    int type = 1;

    for(auto& pair : m){
        type *= pair.second + 1;
    }

    type -= 1;

    return type;
}

int main(){
    cout << solution({ {"a", "a"}, {"b", "b"}, {"c", "a"} });
}
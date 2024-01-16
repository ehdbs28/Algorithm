#include<iostream>
#include<map>

using namespace std;

int main(){
    map<string, int> map;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        map[str]++;
    }

    for(auto& pair : map){
        cout << pair.first << " " << pair.second << "\n";
    }
}
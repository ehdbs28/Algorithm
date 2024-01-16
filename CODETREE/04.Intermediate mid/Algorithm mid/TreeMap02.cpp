#include<iostream>
#include<map>

using namespace std;

int main(){
    map<int, int> m;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int num;
        cin >> num;
        if(m.find(num) == m.end()){
            m[num] = i;
        }
    }

    for(auto& pair : m){
        cout << pair.first << " " << pair.second << "\n";
    }
}
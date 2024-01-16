#include<iostream>
#include<map>

using namespace std;

int main(){
    cout << fixed;
    cout.precision(4);

    map<string, int> m;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string color;
        cin >> color;
        m[color]++;
    }

    for(auto& pair : m){
        cout << pair.first << " " << (float)((float)pair.second / (float)n) * 100 << "\n";
    }
}
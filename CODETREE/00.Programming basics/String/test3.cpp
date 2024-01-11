#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    char st;
    int cnt = 0;
    float avg = 0;
    cin >> st;

    for(auto str : v){
        if(str[0] == st){
            cnt++;
            avg += str.length();
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << cnt << " " << avg / cnt;
}
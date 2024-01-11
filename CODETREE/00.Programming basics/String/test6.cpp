#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    int cnt = 0;

    cin >> a >> b;

    for(int i = 0; i < a.length() - 1; i++){
        if(a[i] == b[0] && a[i + 1] == b[1]){
            cnt++;
        }
    }

    cout << cnt;
}
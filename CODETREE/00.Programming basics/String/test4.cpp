#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i = str.length() - 1; i >= 0; i--){
        if(i % 2 == 1){
            cout << str[i];
        }
    }
}
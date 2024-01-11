#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;

    char ans = str[0];
    char target = str[1];

    for(int i = 0; i < str.length(); i++){
        if(str[i] == target){
            str[i] = ans;
        }
    }

    cout << str;
}
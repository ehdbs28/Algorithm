#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(isupper(str[i])){
            str[i] = 'a' + (str[i] - 'A');
        }
        else{
            str[i] = 'A' + (str[i] - 'a');
        }
    }

    cout << str;
}
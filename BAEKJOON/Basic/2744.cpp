#include<iostream>
#include<string>

using namespace std;

int main(){
    string input;

    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            cout << (char)tolower(input[i]);
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            cout << (char)toupper(input[i]);
        }
    }
}
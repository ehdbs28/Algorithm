#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string input = "", normalString = "";

    while(true){
        cin >> input;
        if(input == "0") break;
        normalString = input;
        reverse(input.begin(), input.end());

        cout << (input == normalString ? "yes" : "no") << "\n";
    }
}
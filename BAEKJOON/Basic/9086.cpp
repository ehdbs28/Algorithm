#include<iostream>
#include<string>

using namespace std;

int main(){
    int count;
    string input;

    cin >> count;

    while(count--){
        cin >> input;
        cout << *input.begin() << *(--input.end()) << "\n";
    }
}
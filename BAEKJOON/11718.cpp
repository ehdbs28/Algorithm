#include<iostream>
#include<string>

using namespace std;

int main(){
    while(1){
        string input;
        getline(cin, input);

        if(cin.eof())
            break;
        
        cout << input << "\n";
    }
}
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<char, int> m;
    string str;

    cin >> str;

    for(char ch : str){
        m[ch]++;
    }

    for(char ch : str){
        if(m[ch] == 1){
            cout << ch;
            return 0;
        }
    }
    cout << "None";
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string input;

    cin >> input;

    sort(input.begin(), input.end(), [](char a, char b){
        return (a - '0') > (b - '0');
    });

    cout << input;
}
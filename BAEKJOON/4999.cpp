#include<iostream>
#include<string>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    cout << (a.length() >= b.length() ? "go" : "no");
}
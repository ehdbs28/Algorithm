#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    getline(cin, a);
    getline(cin, b);

    while(a.find(" ") != string::npos){
        a.erase(a.find(" "), 1);
    }
    while(b.find(" ") != string::npos){
        b.erase(b.find(" "), 1);
    }

    cout << a + b;
}
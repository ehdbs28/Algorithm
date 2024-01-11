#include <iostream>

using namespace std;

int main() {
    string a;
    cin >> a;
    a.erase(a.find("e"), 1);
    cout << a;
}
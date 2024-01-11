#include <iostream>

using namespace std;

int main() {
    char ch;
    cin >> ch;
    ch--;

    cout << (ch >= 'a' ? ch : 'z');
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    int maxLen = max(a.length(), max(b.length(), c.length()));
    int minLen = min(a.length(), min(b.length(), c.length()));

    cout << maxLen - minLen;
}
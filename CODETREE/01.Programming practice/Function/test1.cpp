#include <iostream>

using namespace std;

int getAns(int a, int b){
    int mul = a * b;
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return mul / a;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << getAns(n, m);
}
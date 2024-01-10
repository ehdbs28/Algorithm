#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = n; i > 0; i--){
        for(int t = 0; t < n - i; t++){
            cout << "  ";
        }
        for(int j = 0; j < (n * 2 - 1) - 2 * (n - i); j++){
            cout << "* ";
        }
        cout << "\n";
    }
}
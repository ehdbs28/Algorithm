#include <iostream>

using namespace std;

int main() {
    int n;
    int row = 1;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < row; j++){
            cout << "*";
        }
        cout << "\n";
        row += 2;
    }
}
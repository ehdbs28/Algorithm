#include <iostream>

using namespace std;

int main() {
    int n;
    int row = 1;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int t = 0; t < n - i - 1; t++){
            cout << "  ";
        }
        for(int j = 0; j < row; j++){
            cout << "* ";
        }
        row += 2;
        cout << "\n";
    }
}
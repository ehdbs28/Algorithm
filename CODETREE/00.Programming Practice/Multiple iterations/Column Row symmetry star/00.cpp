#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int row = n * 2 - 1;
    int space = 0;

    for(int i = 0; i < n * 2 - 1; i++){
        for(int j = 0; j < space; j++){
            cout << "  ";
        }
        for(int j = 0; j < row; j++){
            cout << "* ";
        }
        cout << "\n";

        if(i < n - 1){
            space++;
            row -= 2;
        }
        else{
            space--;
            row += 2;
        }
    }
}
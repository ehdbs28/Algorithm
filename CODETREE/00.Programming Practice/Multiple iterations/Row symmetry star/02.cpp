#include <iostream>

using namespace std;

int main() {
    int n;
    int row = 1;
    cin >> n;

    for(int i = 0; i < n * 2 - 1; i++){
        for(int j = 0; j < row; j++){
            cout << "*";
        }
        cout << "\n\n";

        if(i < n - 1){
            ++row;
        }
        else{
            --row;
        }
    }
}
#include <iostream>

using namespace std;

int main() {
    int prev;

    for(int i = 0; i < 10; i++){
        int num;
        cin >> num;

        if(num % 3 == 0){
            cout << prev;
            break;
        }

        prev = num;
    }
}
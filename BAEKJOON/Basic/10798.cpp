#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    char array[5][15] = {};

    for(int row = 0; row < 5; row++){
        cin >> array[row];
    }

    for(int column = 0; column < 15; column++){
        for(int row = 0; row < 5; row++){
            if(array[row][column] == 0) continue;

            cout << array[row][column];
        }
    }
}
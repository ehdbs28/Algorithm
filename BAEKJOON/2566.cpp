#include<iostream>

using namespace std;

int main(){
    const int array_size = 9;
    int max_num = -1, row = 0, column = 0, temp;

    for(int rowi = 0; rowi < array_size; rowi++){
        for(int columni = 0; columni < array_size; columni++){
            cin >> temp;
            if(max_num < temp){
                max_num = temp;
                row = rowi;
                column = columni;
            }
        }
    }

    cout << max_num << "\n" << row + 1 << " " << column + 1;
}
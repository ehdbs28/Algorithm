#include<iostream>

using namespace std;

int main(){
    int maxNum = 0, index = 0, input;

    for(int i = 0; i < 9; i++){
        cin >> input;
        if(input > maxNum){
            maxNum = input;
            index = i + 1;
        }
    }

    cout << maxNum << "\n" << index;
}
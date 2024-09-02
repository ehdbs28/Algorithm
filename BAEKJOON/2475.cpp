#include<iostream>

using namespace std;

int main(){
    int num, powSum = 0;
    for(int i = 0; i < 5; i++){
        cin >> num;
        powSum += num * num;
    }

    cout << powSum % 10;
}
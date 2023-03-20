#include<iostream>

using namespace std;

int main(){
    int arraySize, minNum = 1000000, maxNum = -1000000;

    cin >> arraySize;

    while(arraySize--){
        int num;
        cin >> num;

        maxNum = max(maxNum, num);
        minNum = min(minNum, num);
    }

    cout << minNum << " " << maxNum;
}
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        int length = 0, index = 0, printCnt = 0;
        cin >> length >> index;

        int* printQue = new int[length];

        for(int j = 0; j < length; j++)
            cin >> printQue[j];
        
        int* indexPoint = printQue + index;
        sort(printQue, (printQue + length), greater<>());

        for(int k = 0; k < length; k++){
            printCnt++;
            if(printQue + k == indexPoint){
                cout << printCnt << "\n";
                break;
            }
        }
    }
}
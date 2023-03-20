#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> array;
    int arraySize;
    int findNum;

    cin >> arraySize;

    while(arraySize--){
        int num;
        cin >> num;

        if(array.count(num) > 0){
            array[num]++;
        }
        else{
            array.insert({ num, 1 });
        }
    }

    cin >> findNum;
    cout << array[findNum];
}
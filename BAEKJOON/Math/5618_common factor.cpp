#include<iostream>
#include<string>
#include<vector>

using namespace std;

int GetMaxNum(int array[], int lenght);

int main(){
    int maxNum;

    int length;
    cin >> length;

    int *nums = new int[length];

    for(int i = 0; i < length; i++){
        cin >> nums[i];
    }

    maxNum = GetMaxNum(nums, length);

    for(int i = 1; i <= maxNum; i++){
        int same = 0;
        for(int j = 0; j < length; j++){
            if(nums[j] % i == 0){
                same++;
            } 
        }
        if(same >= length) cout << i << endl;
    }
}

int GetMaxNum(int array[], int length){
    int maxNum = 0;
    for(int i = 0; i < length; i++){
        if(array[i] > maxNum){
            maxNum = array[i];
        }
    }

    return maxNum;
}
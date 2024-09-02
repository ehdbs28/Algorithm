#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    vector<int> array;

    int count, target, input, temp = 0, maxNum = 0;

    cin >> count >> target;

    for(int i = 0; i < count; i++){
        cin >> input;
        array.push_back(input);
    }

    for(int i = 0; i < count - 2; i++){
        for(int j = i + 1; j < count - 1; j++){
            for(int k = j + 1; k < count; k++){
                temp = array[i] + array[j] + array[k];

                if(temp == target){
                    cout << temp;
                    return 0;
                }

                if(temp < target)
                    maxNum = max(maxNum, temp);
            }
        }
    }

    cout << maxNum;
}
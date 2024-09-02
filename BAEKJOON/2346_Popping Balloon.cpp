#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool check[1000] = {true, false};

int FindAIndex(int max, int currentIndex, int value){
    int checkValue = 0;
    for(int i = ((value > 0) ? 1 : -1); ((value > 0) ? i <= value : i >= value); ((value > 0) ? i++ : i--)){
        checkValue = currentIndex + i;

        while(checkValue > max || checkValue <= 0){
            if(checkValue > max)
                checkValue -= max;
            else if(checkValue <= 0)
                checkValue = max - abs(checkValue);
        }

        if(check[checkValue - 1]){
            currentIndex += (value > 0) ? 1 : -1;
            (value > 0) ? --i : ++i;
        }
    }

    check[checkValue - 1] = true;
    return checkValue;
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int ballonCount;
    int index = 1;

    vector<int> ballonNums;

    cin >> ballonCount;

    for(int i = 0; i < ballonCount; i++){
        int input;
        cin >> input;
        ballonNums.push_back(input);
    }

    for(int i = 0; i < ballonCount; i++){
        cout << index << " ";
        if(i < ballonCount - 1)
            index = FindAIndex(ballonCount, index, ballonNums[index - 1]);
    }
}


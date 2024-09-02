#include<iostream>
#include<math.h>
#include<queue>

using namespace std;

int main(){
    queue<int> modes;
    int numbers[8001] = {};

    int numCount, centerCount, input;
    int sum = 0, minNum = 4001, maxNum = -4001, center = 0, mode = 1;

    cin >> numCount;
    centerCount = numCount / 2 + 1;

    for(int i = 0; i < numCount; i++){
        cin >> input;
        sum += input;

        minNum = min(minNum, input);
        maxNum = max(maxNum, input);

        ++numbers[4000 + input];
    }

    for(int i = 0; i < 8001; i++){
        if(!numbers[i]) continue;

        if(centerCount > 0){
            centerCount -= numbers[i];
            if(centerCount <= 0) center = i - 4000;
        }

        if(numbers[i] > mode){
            modes = queue<int>();
            modes.push(i - 4000);
            mode = numbers[i];
        }
        else if(numbers[i] == mode){
            modes.push(i - 4000);
        }
    }

    if(modes.size() > 1)
        modes.pop();

    cout << (int)round((double)sum / numCount) << "\n" << center << "\n" << modes.front() << "\n" << maxNum - minNum;
}
#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int nums[1000001] = {};
    int min, max;

    cin >> min >> max;

    for(int i = 2; i <= max; i++){
        nums[i] = i;
    }

    for(int i = 2; i <= sqrt(max); i++){
        if(nums[i] == 0)
            continue;
        
        for(int j = i * i; j <= max; j += i)
            nums[j] = 0;
    }

    for(int i = 2; i <= max; i++){
        if(nums[i] != 0 && i >= min)
            cout << i << "\n";
    }
}
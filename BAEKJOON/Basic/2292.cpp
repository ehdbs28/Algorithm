#include<iostream>

using namespace std;

int main(){
    int target;

    int nums = 1;
    int count = 0;

    cin >> target;

    while(nums < target){
        nums += 6 * count;
        ++count;
    }

    if(!count) count = 1;

    cout << count;
}
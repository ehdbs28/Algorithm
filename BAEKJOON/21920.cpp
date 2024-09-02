#include<iostream>
#include<vector>

using namespace std;

int getGCD(int a, int b){
    return b ? getGCD(b, a % b) : a;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> nums;
    int lenght;
    int target;
    int num;

    double hap = 0;
    double cnt = 0;

    cin >> lenght;

    for(int i = 0; i < lenght; i++){
        cin >> num;
        nums.push_back(num);
    }

    cin >> target;

    for(int i = 0; i < lenght; i++){
        if(getGCD(nums[i], target) == 1){
            hap += nums[i];
            ++cnt;
        }
    }

    cout.precision(7);
    cout << (double)hap / cnt;
}
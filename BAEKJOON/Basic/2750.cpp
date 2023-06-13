#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> nums;
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        nums.push_back(input);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++){
        cout << nums[i] << "\n";
    }
}
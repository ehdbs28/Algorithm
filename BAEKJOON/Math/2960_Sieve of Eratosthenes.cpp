#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n, k;
    vector<int> nums;

    cin >> n >> k;

    for(int i = 2; i <= n; i++){
        nums.push_back(i);
    }

    while(!nums.empty()){
        int temp = nums.front();

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % temp == 0){
                if(--k == 0){
                    cout << nums[i];
                    return 0;
                }

                nums.erase(nums.begin() + i);
            }
        }
    }
}
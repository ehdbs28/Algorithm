#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    int answer = 1;
    int up = 1;
    int down = 1;

    int nums[100001] = {};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < n - 1; i++){
        if(nums[i] >= nums[i + 1])
            up++;
        else
            up = 1;

        if(nums[i] <= nums[i + 1])
            down++;
        else
            down = 1;

        answer = max(answer, max(up, down));
    }

    cout << answer;
}
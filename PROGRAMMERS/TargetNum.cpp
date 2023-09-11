#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

int ans = 0;

void DFS(int i, int sum, int target, int sign , vector<int> nums){
    sum += nums[i] * sign;

    if(i + 1 >= nums.size()){
        if(sum == target)
            ans++;
        return;
    }

    DFS(i + 1, sum, target, 1, nums);
    DFS(i + 1, sum, target, -1, nums);
}

int solution(vector<int> numbers, int target) {
    ans = 0;
    DFS(0, 0, target, 1, numbers);
    DFS(0, 0, target, -1, numbers);

    return ans;
}

int main(){
    cout << solution({ 1, 1, 1, 1, 1}, 3) << "\n";
    cout << solution({4, 1, 2, 1}, 2);
}
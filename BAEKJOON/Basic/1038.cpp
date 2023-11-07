#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> nums;

void DFS(long long cur){
    nums.push_back(cur);

    int last = cur % 10;

    if(last <= 0){
        return;
    }

    for(int i = last - 1; i >= 0; --i){
        long long num = cur * 10 + i;
        DFS(num);
    }
}

int main(){
    int k;
    cin >> k;

    if(k >= 1023){
        cout << -1;
    }
    else{
        for(int i = 0; i < 10; i++){
            DFS(i);
        }

        sort(nums.begin(), nums.end());

        cout << nums[k];
    }
}
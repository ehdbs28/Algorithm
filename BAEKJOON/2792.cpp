#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> nums;

    int n, m;
    int answer;

    int left = 1;
    int right = 0;
    int mid;
    
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int cnt;
        cin >> cnt;

        nums.push_back(cnt);
        right = max(right, cnt);
    }

    while(left <= right){
        mid = (left + right) / 2;

        int count = 0;
        for(int i = 0; i < m; i++){
            count += nums[i] / mid;
            if(nums[i] % mid != 0){
                count++;
            }
        }

        if(count <= n){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << answer;
}
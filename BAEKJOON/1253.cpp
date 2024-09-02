#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> nums;

bool isGoodNum(int targetIndex)
{
    int val = nums[targetIndex];
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int sum = nums[left] + nums[right];

        if(sum < val)
        {
            left++;
        }
        else if(sum > val)
        {
            right--;
        }
        else
        {
            if(left != targetIndex && right != targetIndex)
            {
                return true;
            }
            else if(left == targetIndex)
            {
                left++;
            }
            else if(right == targetIndex)
            {
                right--;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n;
    nums.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(isGoodNum(i))
        {
            ans++;
        }
    }
    cout << ans;
}
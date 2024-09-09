#include<iostream>

using namespace std;

int n;

int arr[200001] = {};
int cnt[10] = {};

int answer = 0;

int GetCnt()
{
    int temp = 0;

    for(int i = 0; i < 10; i++)
    {
        if(cnt[i] > 0)
        {
            temp++;
        }
    }

    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    cnt[arr[left]]++;

    while(left <= right && right < n)
    {
        int temp = GetCnt();

        if(temp > 2)
        {
            cnt[arr[left]]--;
            left++;
        }
        else
        {
            answer = max(answer, right - left + 1);
            right++;
            cnt[arr[right]]++;
        }
    }

    cout << answer;
}
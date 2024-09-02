#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int main(){
    int n;
    long long arr[5001] = {};

    long long ans = LONG_LONG_MAX;
    long long ansArr[3] = {};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n - 2; i++){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            long long sum = arr[i] + arr[l] + arr[r];

            if(abs(sum) < ans){
                ans = abs(sum);
                ansArr[0] = arr[i];
                ansArr[1] = arr[l];
                ansArr[2] = arr[r];
            }

            if(sum > 0){
                r--;
            }
            else{
                l++;
            }
        }
    }

    sort(ansArr, ansArr + 3);

    for(int i = 0; i < 3; i++){
        cout << ansArr[i] << " ";
    }
}
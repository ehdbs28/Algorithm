#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int main(){
    int n;
    int ans = INT_MAX;
    int ansL;
    int ansR;
    int arr[100001] = {};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int l = 0;
    int r = n - 1;

    while(l < r){
        int sum = arr[l] + arr[r];

        if(abs(sum) < ans){
            ans = abs(sum);
            ansL = arr[l];
            ansR = arr[r];
        }

        if(sum > 0){
            r--;
        }
        else{
            l++;
        }
    }

    cout << ansL << " " << ansR;
}
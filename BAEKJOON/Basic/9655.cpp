#include<iostream>

using namespace std;

int main(){
    int dp[1000] = {};
    int n;

    cin >> n;

    cout << (n % 2 == 0 ? "CY" : "SK"); 
}
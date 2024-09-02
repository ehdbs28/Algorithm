#include<iostream>

using namespace std;

int dp[41] = { 0, 1, 1 };

int fib(int n) {
    if (n == 1 || n == 2)
        return 1; 
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    dp[1] = dp[2] = 1;
    int cnt = 0;
    for( int i = 3; i <= n; i++){
        ++cnt;
        dp[i] <- dp[i - 1] + dp[i - 2]; 
    }
    return cnt;
}

int main(){
    int n;

    cin >> n;

    cout << fib(n) << " " << fibonacci(n);
}
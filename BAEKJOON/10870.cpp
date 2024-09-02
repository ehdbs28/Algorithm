#include<iostream>

using namespace std;

int fibo(int n);

int fibos[20] = { 0, 1, 1 };

int main(){
    int n;
    cin >> n;
    fibo(n);
    cout << fibos[n];
}

int fibo(int n){
    if(n <= 2)
        return 1;

    fibos[n] = fibo(n - 2) + fibo(n - 1);
    return fibos[n - 2] + fibos[n - 1];
}
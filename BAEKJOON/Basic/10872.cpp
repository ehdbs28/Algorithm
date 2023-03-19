#include<iostream>

using namespace std;

int Factorial(int n);

int main(){
    int n;
    cin >> n;

    cout << Factorial(n);
}

int Factorial(int n){
    if(n <= 1)
        return 1;
        
    return n * Factorial(n - 1);
}
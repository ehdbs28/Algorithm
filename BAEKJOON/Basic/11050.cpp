#include<iostream>

using namespace std;

int factorial(int);

int main(){
    int N, K;

    cin >> N >> K;

    cout << factorial(N) / (factorial(N - K) * factorial(K));
}

int factorial(int n){
    int answer = 1;

    for(int i = 2; i <= n; i++){
        answer *= i;
    }

    return answer;    
}

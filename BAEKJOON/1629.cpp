#include<iostream>

using namespace std;

long long a;
long long b;
long long c;

long long getNum(long long n){
    if(n == 1){
        return a % c;
    }

    long long x = getNum(n / 2) % c;
    if(n % 2 == 0){
        return (x * x) % c;
    }
    else{
        return (((x * x) % c) * a) % c;
    }
}

int main(){
    cin >> a >> b >> c;
    cout << getNum(b);
}
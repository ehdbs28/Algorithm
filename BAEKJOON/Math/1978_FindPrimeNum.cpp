#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Get_PrimeNum(int n);

int main(){
    int cnt = 0;
    int primeNum = 0;

    cin >> cnt;
    
    for(int i = 0; i < cnt; i++){
        int n = 0;
        cin >> n;
        primeNum += Get_PrimeNum(n);
    }

    cout << primeNum;
}

int Get_PrimeNum(int n){
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            if(n == i) return 1;
            else return 0;
        }
    }

    return 0;
}
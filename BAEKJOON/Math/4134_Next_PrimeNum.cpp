#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long GetNextPrimeNum(long long num);

int main(){
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        long long num = 0;
        cin >> num;
        cout << GetNextPrimeNum(num) << "\n";
    }
}

long long GetNextPrimeNum(long long num){
    if(num < 2)
        return 2;

    while(true){
        bool isPrime = true;
        
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime)
            return num;

        ++num;
    }
    return 0;
}
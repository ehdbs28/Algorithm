#include<iostream>
#include<math.h>

using namespace std;

bool GetNextPrimeNum(long long num);

int main(){
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        long num = 0;
        cin >> num;
        cout << GetNextPrimeNum(num);
    }
}

bool GetNextPrimeNum(long long num){

    for(long long i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }
}
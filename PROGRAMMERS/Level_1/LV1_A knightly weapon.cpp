#include<iostream>

using namespace std;

int solution(int number, int limit, int power);

int main(){
    int number;
    int limit;
    int power;

    cin >> number >> limit >> power;

    cout << solution(number, limit, power);
}

int solution(int number, int limit, int power){
    int value = 0;
    int divisor = 0;

    for(int i = 1; i <= number; i++){
        for(int j = 1; j * j <= i; j++){
            if(j * j == i) divisor++;
            else if(i % j == 0) divisor += 2;
        }

        if(divisor > limit) value += power;
        else value += divisor;

        divisor = 0;
    }

    return value;
}
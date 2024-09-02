#include<iostream>
#include<cmath>

using namespace std;

long long solution(int price, int money, int count);

int main(){
    solution(3, 20, 4);
}

long long solution(int price, int money, int count){
    long long answer;
    long long Price = 0;

    for(int i = 1; i <= count; i++){
        Price += price * i; 
    }

    answer = money - Price;

    return answer < 0 ? abs(answer) : 0;
}
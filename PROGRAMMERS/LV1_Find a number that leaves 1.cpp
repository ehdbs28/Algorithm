#include<iostream>

using namespace std;

int solution(int n);

int main(){
    cout << solution(12);
}

int solution(int n){
    for(int i = 1; i < n; i++){
        if(n % i == 1)
            return i;
    }

    return 0;   
}
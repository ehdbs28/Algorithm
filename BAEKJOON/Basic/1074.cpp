#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    int r;
    int c;

    int answer = 0;

    cin >> n >> r >> c;

    while(n >= 0){
        --n;

        // 1 사분면
        if(pow(2, n) > r && pow(2, n) > c){
            answer += 0;
        }
        // 2 사분면
        else if(pow(2, n) > r && pow(2, n) <= c){
            c -= pow(2, n);
            answer += pow(2, n) * pow(2, n);
        }
        // 3 사분면
        else if(pow(2, n) <= r && pow(2, n) > c){
            r -= pow(2, n);
            answer += pow(2, n) * pow(2, n) * 2;
        }
        // 4 사분면
        else{
            c -= pow(2, n);
            r -= pow(2, n);
            answer += pow(2, n) * pow(2, n) * 3;
        }
    }

    cout << answer;
}
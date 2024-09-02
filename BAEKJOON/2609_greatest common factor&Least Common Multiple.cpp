#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int input1 = 0, input2 = 0;

    int GCF = 0; //최대공약수
    int LCM = 0; //최소공배수

    cin >> input1 >> input2;
    if(input1 != 0 && input2 != 0){
        GCF += 1;
        LCM += 1;
    }

    int max = input1 > input2 ? input1 : input2;

    for(int i = 2; i <= max; i++){ //max 값 까지의 소수 구하기
        for(int j = 2; j <= i; j++){
            if(i % j == 0){
                if(i == j){ // i는 소수
                    if(input1 % i == 0 && input2 % i == 0){ //최대공약수, 최소공배수 계산
                        GCF *= i;
                        LCM *= i;
                        input1 /= i;
                        input2 /= i;
                        
                        i = 1;
                    }
                }
                break;
            }
        }
    }
    LCM *= input1 * input2;

    cout << GCF << "\n" << LCM;
}
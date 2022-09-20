#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    string n = "";
    int b = 0;
    long long nToInt = 0;

    vector<int> vec;

    cin >> n >> b;

    for(int i= 0; i < n.length() / 2; i++){ //문자열 거꾸로 쓰기
        char temp = n[n.length() - (i + 1)];
        n[n.length() - (i + 1)] = n[i];
        n[i] = temp;
    }

    for(int i = 0; i < n.length(); i++){ 
        if(n[i] >= 65 && n[i] <= 90){ //아스키코드를 이용하여 Char형을 Int형으로 바꿔줌
            vec.push_back(n[i] - 55);
        }
        else vec.push_back(n[i] - 48);
    }

    for(int i = 0; i < vec.size(); i++){
        long long _pow = 0;
        _pow = pow(b, i);
        nToInt += vec[i] * _pow; //진수 변환
    }

    cout << nToInt;
}
#include<iostream>

using namespace std;

int main(){
    int a, b, c, maxNum = 0;

    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 & c == 0)
            return 0;
        
        maxNum = max(max(a, b), c);

        if(maxNum == a){
            cout << ((maxNum * maxNum == (b * b + c * c)) ? "right" : "wrong") << "\n";
        }
        else if(maxNum == b){
            cout << ((maxNum * maxNum == (a * a + c * c)) ? "right" : "wrong") << "\n";
        }
        else{
            cout << ((maxNum * maxNum == (b * b + a * a)) ? "right" : "wrong") << "\n";
        }
    }
}
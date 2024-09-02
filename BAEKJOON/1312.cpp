#include<iostream>

using namespace std;

int main(){
    int a, b, n;
    int remain = 0;

    cin >> a >> b >> n;

    if(a % b == 0){
        cout << 0;
        return 0;
    }

    if(a > b) a %= b;

    for(int i = 0; i < n; i++){
        a *= 10;
        remain = (int)(a / b);
        a %= b;
    }

    cout << remain;
}
#include<iostream>

using namespace std;

int main(){
    int n;
    int zeroCnt = 0;

    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }
    cout << (n / 5 + n / 25 + n / 125);
}
#include<iostream>

using namespace std;

int main(){
    int n;

    int num = 0;
    int cnt = 0;

    cin >> n;

    n -= num;

    while(n > 0){
        ++num;
        n -= num;
        if(n % num == 0){
            ++cnt;
        }
    }

    cout << cnt;
}
#include<iostream>

using namespace std;

int main(){
    long s;
    long n = 1;
    long c = 0;

    cin >> s;

    while(true){
        c += n++;
        if(c > s)
            break;
    }

    cout << n - 2;
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int AwardCoin(int a, int b, int c);
int Max(int a, int b, int c);

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << AwardCoin(a, b, c);
}

int AwardCoin(int a, int b, int c){
    int coin = 0;

    if(a == b && a == c && b == c){
        coin = 10000 + (a * 1000);
    }
    else if(a == b || a == c){
        coin = 1000 + (a * 100);
    }
    else if(b == c){
        coin = 1000 + (b * 100);
    }
    else if(a != b && a != c && b != c){
        coin = Max(a, b, c) * 100;
    }
    return coin;
}

int Max(int a, int b, int c){
    return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
}
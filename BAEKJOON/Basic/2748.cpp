#include<iostream>

using namespace std;

long long fibos[91] = { 0, 1, 1 };

int main(){
    int n;
    cin >> n;
    
    for(int i = 3; i <= n; i++){
        fibos[i] = fibos[i - 2] + fibos[i - 1];
    }

    cout << fibos[n];
}
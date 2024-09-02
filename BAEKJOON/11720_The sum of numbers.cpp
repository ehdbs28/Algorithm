#include<iostream>
#include<string>

using namespace std;

int main(){
    int sum = 0;
    
    int n;
    string numbers;

    cin >> n >> numbers;

    for(int i = 0; i < n; i++){
        sum += (int)(numbers[i] - 48);
    }

    cout << sum;
}
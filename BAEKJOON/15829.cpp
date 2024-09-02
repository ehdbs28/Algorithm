#include<iostream>
#include<string>

using namespace std;

const unsigned long m = 1234567891;

int main(){

    int lenght;
    unsigned long hash = 0;
    string input;

    cin >> lenght >> input;

    for(int i = lenght - 1; i >= 0; i--){
        int a = input[i] - 'a' + 1;
        hash = (((hash << 5) - hash) + a) % m;
    }

    cout << hash % m;
}
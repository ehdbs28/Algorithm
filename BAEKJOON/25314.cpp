#include<iostream>

using namespace std;

int main(){
    int byte;
    cin >> byte;

    do{
        cout << "long ";
    }
    while(byte -= 4);

    cout << "int";
}
#include<iostream>
#include<string>

using namespace std;

int main(){
    int height;
    cin >> height;

    for(int i = height - 1; i > 0; i--){
        for(int j = i; j > 0; j--){
            cout << "a";
        }
        for(int j = 1; j <= i + 1; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
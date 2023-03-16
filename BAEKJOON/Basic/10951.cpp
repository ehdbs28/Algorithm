#include<iostream>

using namespace std;

int main(){
    int a, b;

    while (1)
    {
        cin >> a >> b;

        if(cin.eof()){
            break;
        }
        else{
            cout << a + b << "\n";
        }
    }
    
}
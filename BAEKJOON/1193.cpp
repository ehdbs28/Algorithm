#include<iostream>

using namespace std;

int main(){
    int x;
    int line = 1;
    
    int a = 0;
    int b = 0;
    
    cin >> x;
    
    while(x > line){
        x -= line++;
    }
    
    if(line % 2 == 0){
        a = x;
        b = line - x + 1;
    }
    else{
        a = line - x + 1;
        b = x;
    }
    
    cout << a << "/" << b;
}

#include<iostream>

using namespace std;

int main(){
    int star;
    cin >> star;

    for(int i = 0; i < star; i++){
        for(int j = 1; j <= star; j++){
            if(star - j > i){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        if(i < star - 1) cout << "\n";
    }
}
#include<iostream>

using namespace std;

void star(int, int, int);

int main(){
    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            star(n, i, j);
        }
        cout << "\n";
    }
}

void star(int n, int i, int j){
    if((i / n) % 3 == 1 && (j / n) % 3 == 1)
        cout << " ";
    else if(n < 3)
        cout << "*";
    else
        star(n / 3, i, j);
}
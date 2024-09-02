#include<iostream>

using namespace std;

int main(){
    int cnt;
    int x = 0;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int dol;
        cin >> dol;
        x = x ^ dol;
    }

    if(x == 0){
        cout << "cubelover";
    }
    else{
        cout << "koosaga";
    }
}
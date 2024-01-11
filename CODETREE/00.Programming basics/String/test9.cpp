#include <iostream>

using namespace std;

int main() {
    string scr;
    string con;
    int st = 0;

    cin >> scr >> con;

    for(int i = 0; i < con.length(); i++){
        if(con[i] == 'L'){
            ++st;
            if(st >= scr.length()){
                st = 0;
            }
        }
        else if(con[i] == 'R'){
            --st;
            if(st < 0){
                st = scr.length() - 1;
            }
        }
    }

    for(int i = st; i < scr.length(); i++){
        cout << scr[i];
    }
    for(int i = 0; i < st; i++){
        cout << scr[i];
    }
}
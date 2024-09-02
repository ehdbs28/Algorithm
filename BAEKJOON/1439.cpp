#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;

    bool b = false;
    int zero = 0;
    int one = 0;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            if((zero == 0 && one == 0) || b){
                b = false;
                zero++;
            }
        }
        else{
            if((zero == 0 && one == 0) || !b){
                b = true;
                one++;
            }
        }
    }

    cout << min(zero, one);
}
#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    int type = -2;

    string last = "";

    cin >> n;

    for(int i = 0; i < n; i++){
        string input;
        int _type;

        cin >> input;

        if(last != ""){
            if(last >= input){
                _type = -1;
            }
            else if(last <= input){
                _type = 1;
            }

            if(type == -2){
                type = _type;
            }
            else{
                if(type != _type){
                    type = 0;
                    break;
                }
            }
        }

        last = input;
    }

    if(type == -1){
        cout << "DECREASING";
    }
    else if(type == 0){
        cout << "NEITHER";
    }
    else{
        cout << "INCREASING";
    }
}
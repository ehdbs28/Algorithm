#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool ascending = false;
    int input, lastNum = 0;

    for(int i = 0; i < 8; i++){
        cin >> input;

        if(i == 0){
            if(input == 1){
                ascending = true;
            }
            else if(input == 8){
                ascending = false;
            }
            else{
                cout << "mixed";
                return 0;
            }
        }
        else{
            if(ascending){
                if(input != lastNum + 1){
                    cout << "mixed";
                    return 0;
                }
            }
            else{
                if(input != lastNum - 1){
                    cout << "mixed";
                    return 0;
                }
            }
        }
        lastNum = input;
    }

    cout << (ascending ? "ascending" : "descending");
}
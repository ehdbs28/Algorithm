#include<iostream>
#include<string>

using namespace std;

bool IsCurrectMovie(string a);

int main(){
    int movieNum;

    int num = 666;
    int movie = 0;

    cin >> movieNum;

    while(true){
        if(IsCurrectMovie(to_string(num))){
            movie = num;
            --movieNum;
            if(movieNum == 0){
                break;
            }
        }

        ++num;
    }

    cout << movie;
}

bool IsCurrectMovie(string a){
    int count = 0;

    for(auto ch : a){
        if(ch == '6'){
            if(++count == 3) return true;
        }
        else count = 0;
    }

    return false;
}
#include<iostream>
#include<string>

using namespace std;

int main(){
    string input;
    int wordCnt = 0;
    bool isChar = false;

    getline(cin, input);

    for(auto iter = input.begin(); iter <= --input.end(); iter++){
        if(*iter == ' ' && isChar == true){
            ++wordCnt;
            isChar = false;
        }
        else if(*iter != ' '){
            isChar = true;
        }
    }

    cout << ((wordCnt == 0 && !isChar) ? 0 : (isChar ? wordCnt + 1 : wordCnt));
}
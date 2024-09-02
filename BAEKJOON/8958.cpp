#include<iostream>
#include<string>

using namespace std;

int main(){
    int testcase, score = 0, stack = 0;
    string input;

    cin >> testcase;

    while(testcase--){
        cin >> input;
        score = 0; stack = 0;

        for(auto ch : input){
            if(ch == 'O'){
                stack++;
                score += stack;
            }
            else
                stack = 0;
        }

        cout << score << "\n";
    }
}
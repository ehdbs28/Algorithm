#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    string input;
    int bar_count = 0;
    int answer = 0;

    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            bar_count++;
        }
        else{
            --bar_count;

            if(input[i - 1] == '(' && input[i] == ')'){
                answer += bar_count;
            }
            else{
                ++answer;
            }
        }
    }

    cout << answer;
}
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    stack<char> opens;

    string input;

    int answer = 0;
    int multiple = 1;

    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '[' || input[i] == '('){
            opens.push(input[i]);
            
            if(input[i] == '(')
                multiple *= 2;
            else
                multiple *= 3;
        }
        else{
            if(opens.empty() || !((input[i] == ')' && opens.top() == '(') || (input[i] == ']' && opens.top() == '['))){
                cout << 0;
                return 0;
            }

            if(input[i] == ')'){
                if(input[i - 1] == '(')
                    answer += multiple;

                multiple /= 2;
            }
            else{
                if(input[i - 1] == '[')
                    answer += multiple;

                multiple /= 3;
            }

            opens.pop();
        }
    }

    if(!opens.empty())
        cout << 0;
    else
        cout << answer;
}
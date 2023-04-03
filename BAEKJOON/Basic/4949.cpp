#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    int index;
    string input;
    stack<char> temp;

    while(true){
        temp = stack<char>();
        getline(cin, input);
        if(input == ".")
            break;

        for(index = 0; index < input.length(); index++){
            if(!(input[index] == '(' || input[index] == '[' || input[index] == ')' || input[index] == ']'))
                continue;

            if(input[index] == ')' || input[index] == ']'){
                if(temp.empty()){
                    break;
                }
                else if(temp.top() == '(' && input[index] == ']'){
                    break;
                }
                else if(temp.top() == '[' && input[index] == ')'){
                    break;
                }
                else{
                    temp.pop();
                }
            }
            else if(input[index] == '(' || input[index] == '['){
                temp.push(input[index]);
            }
        }

        if(!temp.empty() || index < input.length()){
            cout << "no" << "\n";
            continue;
        }

        cout << "yes" << "\n";
    }
}
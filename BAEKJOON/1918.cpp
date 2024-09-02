#include<iostream>
#include<string>
#include<stack>

using namespace std;

int GetImportance(char oper){
    if(oper == '(')
        return 0;
    if(oper == '+' || oper == '-')
        return 1;
    else
        return 2;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string input;
    stack<pair<char, int>> operators;

    cin >> input;

    for(int i = 0; i < input.length(); i++){
        int importance = GetImportance(input[i]);

        if(isalpha(input[i])){
            cout << input[i];
        }
        else{
            if(input[i] == '(')
                operators.push({input[i], importance});
            else if(input[i] == ')'){
                while(true){
                    if(operators.top().first == '('){
                        operators.pop();
                        break;
                    }

                    cout << operators.top().first;
                    operators.pop();
                }
            }
            else{
                while(!operators.empty() && operators.top().first != '(' && operators.top().second >= importance){
                    cout << operators.top().first;
                    operators.pop();
                }
                operators.push({input[i], importance});
            }
        }
    }

    while(!operators.empty()){
        cout << operators.top().first;
        operators.pop();
    }
}
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    stack<int> stack;
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(stack.empty() == false && stack.top() == '(' && input[i] == ')'){
            stack.pop();
        }
        else{
            stack.push(input[i]);
        }
    }

    cout << stack.size();
}
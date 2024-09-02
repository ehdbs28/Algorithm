#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    int n;
    int answer = 0;

    string input;

    cin >> n;

    while(n--){
        stack<int> stack;
        
        cin >> input;

        for(char ch : input){
            if(!stack.empty() && ch == stack.top()){
                stack.pop();
                continue;
            }

            stack.push(ch);
        }

        if(stack.empty()) ++answer;
    }

    cout << answer;
}
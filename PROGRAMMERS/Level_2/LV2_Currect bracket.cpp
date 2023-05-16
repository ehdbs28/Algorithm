#include<iostream>
#include<stack>
#include<string>
#include<cmath>

using namespace std;

bool solution(string s) {
    stack<int> stack;

    bool answer = true;

    for(int i = 0; i < s.length(); i++){
        if(!stack.empty() && abs(stack.top() - s[i]) == 1 && stack.top() < s[i]){
            stack.pop();
            continue;
        }

        stack.push(s[i]);
    }

    answer = stack.empty();

    return answer;
}

int main(){
    char s[] = "()()";
    cout << solution(s);
}
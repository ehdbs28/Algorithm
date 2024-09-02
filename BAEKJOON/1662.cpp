#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    stack<pair<int, int>> stack;
    string input;

    int cnt = 0;

    cin >> input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '('){
            if(stack.empty())
                --cnt;
            else
                --stack.top().second;

            stack.push({ input[i - 1] - '0', 0 });
        }
        else if(input[i] == ')'){
            int temp = stack.top().second * stack.top().first;
            stack.pop();
            if(stack.empty()){
                cnt += temp;
            }
            else{
                stack.top().second += temp;
            }
        }
        else{
            if(stack.empty())
                ++cnt;
            else
                ++stack.top().second;
        }
    }

    cout << cnt;
}
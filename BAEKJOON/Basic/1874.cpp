#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
    int numbers[100000] = {};
    stack<int> stack;
    queue<char> answer;
    int stackSize, input, insertValue = 1, index = 0;

    cin >> stackSize;

    for(int i = 0; i < stackSize; i++){
        cin >> input;
        numbers[i] = input;
    }

    while (!(insertValue <= stackSize + 1 ^ index < stackSize))
    {
        if(!stack.empty() && stack.top() == numbers[index]){
            stack.pop();
            ++index;
            answer.push('-');
            continue;
        }
        else{
            stack.push(insertValue);
            answer.push('+');
        }

        insertValue++;
    }
    
    if(insertValue > stackSize + 1){
        cout << "NO";
    }
    else{
        while(!answer.empty()){
            cout << answer.front() << "\n";
            answer.pop();
        }
    }

}
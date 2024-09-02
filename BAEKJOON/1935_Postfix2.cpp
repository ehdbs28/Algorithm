#include<iostream>
#include<stack>

using namespace std;

int main(){
    //Input : ABC*+DE/-

    //{1, 2, 3}
    //temp = top -> 3 | {1, 2}
    //{1, 6}
    //temp = top -> 6 | {1}
    //{7}
    //{7, 4, 5}
    //temp = top -> 5 | {7, 4}
    //{7, 0.8}
    //temp = top -> 0.8 | {7}
    //{6.2}

    //answer = 6.2

    int count;
    string input;

    cin >> count; //피연산자 수
    cin >> input;

    double* nums = new double[count];
    stack<double> stack;

    for(int i = 0; i < count; i++) //피연산자 값 입력
        cin >> nums[i];

    for(int i = 0; i < input.length(); i++){
        if(isalpha(input[i])){ // is Alpha? A = 1, a = 2, 1,2 = 0
            stack.push(nums[input[i] - 'A']);
        }
        else{
            double temp = stack.top();
            stack.pop();

            switch (input[i])
            {
                case '+':
                    stack.top() = stack.top() + temp;
                    break;
                case '-':
                    stack.top() = stack.top() - temp;
                    break;
                case '*':
                    stack.top() = stack.top() * temp;
                    break;
                case '/':
                    stack.top() = stack.top() / temp;
                    break;
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << stack.top();
}
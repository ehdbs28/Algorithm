#include<iostream>
#include<stack>

using namespace std;

int main(){
    int count, input, sum = 0;
    stack<int> temp;

    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> input;

        if(!input){
            sum -= temp.top();
            temp.pop();
        }
        else{
            sum += input;
            temp.push(input);
        }
    }

    cout << sum;
}
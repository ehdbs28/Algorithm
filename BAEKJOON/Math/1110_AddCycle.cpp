#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int main(){
    string input;
    queue<char> queue;
    int cnt;

    cin >> input;

    if(input.length() == 1) input.push_back('0');

    queue.push(input[0]);
    queue.push(input[1]);

    do{
        int value1 = queue.front() - '0';
        queue.pop();
        int value2 = queue.front() - '0';

        value1 += value2;

        queue.push(to_string(value1).back());
        cnt++;
    }
    while(queue.front() != input[0] || queue.back() != input[1]);

    cout << cnt;
}
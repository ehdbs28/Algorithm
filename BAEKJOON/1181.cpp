#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct stringSort{
    bool operator()(string a, string b){
        if(a.length() == b.length())
            return a > b;

        return a.length() > b.length();
    }
};

int main(){
    priority_queue<string, vector<string>, stringSort> array;
    int arraySize;
    string input, temp;

    cin >> arraySize;

    for(int i = 0; i < arraySize; i++){
        cin >> input;
        array.push(input);
    }

    for(int i = 0; i < arraySize; i++){
        temp = array.top();
        array.pop();

        if(!array.empty() && temp == array.top())
            continue;

        cout << temp << "\n";
    }
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    vector<int> stack;
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int n;
            cin >> n;
            stack.push_back(n);
        }
        else if(command == "pop" || command == "top"){
            if(stack.empty()) cout << -1;
            else {
                cout << stack[stack.size() - 1];
                if(command == "pop") stack.erase(stack.begin() + stack.size() - 1);
            }
        }
        else if(command == "size"){
            cout << stack.size();
        }
        else if(command == "empty"){
            cout << (int)stack.empty();
        }
    }
}
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<int> queue;

    int orderCount, frontIndex = 0, backIndex = 0, input;
    string order = "";

    cin >> orderCount;

    while(orderCount--){
        cin >> order;

        if(order == "push"){
            cin >> input;
            queue.push_back(input);
            ++backIndex;
        }
        else if(order == "pop"){
            if(frontIndex >= backIndex){
                cout << -1 << "\n";
                continue;
            }
            cout << queue[frontIndex] << "\n";
            ++frontIndex;
        }
        else if(order == "size"){
            cout << backIndex - frontIndex << "\n";
        }
        else if(order == "empty"){
            cout << (frontIndex >= backIndex) << "\n";
        }
        else if(order == "front"){
            if(frontIndex >= backIndex){
                cout << -1 << "\n";
                continue;
            }
            cout << queue[frontIndex] << "\n";
        }
        else if(order == "back"){
            if(frontIndex >= backIndex){
                cout << -1 << "\n";
                continue;
            }
            cout << queue[backIndex - 1] << "\n";
        }
    }
}
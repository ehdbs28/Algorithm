#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    vector<int> queue;
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int n;
            cin >> n;
            queue.push_back(n);
        }
        else if(command == "pop" || command == "front"){
            if(queue.empty()){
                cout << -1 << "\n";
                continue;
            }

            cout << queue.front() << "\n";
            if(command == "pop") queue.erase(queue.begin());
        }
        else if(command == "back"){
            if(queue.empty()){
                cout << -1 << "\n";
                continue;
            }

            cout << queue.back() << "\n";
        }
        else if(command == "size"){
            cout << queue.size() << "\n";
        }
        else if(command == "empty"){
            cout << (int)queue.empty() << "\n";
        }
    }
}
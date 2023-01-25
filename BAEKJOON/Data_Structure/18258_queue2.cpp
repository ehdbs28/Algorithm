#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int* queue = new int[1000];
    int front = -1, back = -1;
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        string command;
        cin >> command;

        if(command == "push"){
            int n;
            cin >> n;
            queue[++back] = n;
        }
        if(command == "pop" || command == "front"){
            if(front == back) cout << -1 << "\n";
            else{
                cout << queue[front + 1];
                if(command == "pop") front++;
            }
        }
        if(command == "back"){
            if(front == back) cout << -1 << "\n";
            else{
                cout << queue[back] << "\n";
            }
        }
        if(command == "size"){
            cout << back - front << "\n";
        }
        if(command == "empty"){
            cout << (int)(front == back) << "\n";
        }
    }
}
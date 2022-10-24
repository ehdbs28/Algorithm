#include<iostream>

using namespace std;

int main(){
    int count;
    cin >> count;

    int* deque = new int[1000];
    int front = 0, back = 0;

    for(int i = 0; i < count; i++){
        string order;
        cin >> order;

        if(order == "push_front"){
            back++;
            int n;
            cin >> n;
            deque[front] = n;
        }
        else if(order == "push_back"){
            back++;
            int n;
            cin >> n;
            deque[back] = n;
        }
        else if(order == "pop_back" || order == "back"){
            if(back - front == 0) cout << -1 << "\n";
            else{
                cout << deque[back] << "\n";
                if(order == "pop_back") back--;
            }
        }
        else if(order == "pop_front" || order == "front"){
            if(back - front == 0) cout << -1 << "\n";
            else{
                cout << deque[front] << "\n";
                if(order == "pop_front") front++;
            }
        }
        else if(order == "size"){
            cout << back - front << "\n";
        }
        else if(order == "empty"){
            cout << ((back - front == 0) ? 1 : 0) << "\n";
        }
    }
}
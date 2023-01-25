#include<iostream>

using namespace std;

int main(){
    int count;
    cin >> count;

    int* deque = new int[10000];
    int front = -1, back = -1;

    for(int i = 0; i < count; i++){
        string order;
        cin >> order;

        if(order == "push_front"){
            int n;
            cin >> n;
            for(int i = back; i >= 0; i--){
                deque[i + 1] = deque[i];
            }
            back++;
            deque[front + 1] = n;
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
                cout << deque[front + 1] << "\n";
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
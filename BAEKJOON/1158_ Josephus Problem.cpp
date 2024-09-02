#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n, k;
    queue<int> _queue;

    cin >> n >> k;
    cout << "<";

    for(int i = 1; i <= n; i++){
        _queue.push(i);
    }

    for(int i = 1; !_queue.empty(); i++){
        if(i % k == 0){
            if(_queue.size() == 1){
                cout << _queue.front();
            }
            else{
                cout << _queue.front() << ", ";
            }

            _queue.pop();
        }
        else{
            int temp = _queue.front();
            _queue.pop();
            _queue.push(temp);
        }
    }
    cout << ">";
}
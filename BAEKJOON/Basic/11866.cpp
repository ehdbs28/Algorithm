#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> queue;
    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        queue.push(i + 1);

    cout << "<";
    while(!queue.empty()){
        for(int i = 0; i < k - 1; i++){
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front() << (queue.size() != 1 ? ", " : "");
        queue.pop();
    }
    cout << ">";
}
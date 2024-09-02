#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> queue;
    
    int n;
    int loopCount;
    int num;

    cin >> n;
    loopCount = n*n;

    for(int i = 0; i < loopCount; i++){
        cin >> num;

        if(queue.size() < n){
            queue.push(num);
        }
        else{
            if(queue.top() < num){
                queue.pop();
                queue.push(num);
            }
        }   
    }

    cout << queue.top();
}
#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> numbers;

    int count;
    int input;

    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> input;

        if(input != 0){
            numbers.push(input);
            continue;
        }

        if(numbers.empty()){
            cout << 0 << "\n";
        }
        else{
            cout << numbers.top() << "\n";
            numbers.pop();
        }
    }
}
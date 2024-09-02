#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int> nums;

    int n;
    int m;

    int answer = 0;
    int temp = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        nums.push(input);
        temp += input;

        while(temp >= m){
            ++answer;
            temp -= nums.top() * 2;
            nums.pop();
        }
    }

    cout << answer;
}
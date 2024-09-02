#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    stack<int> temp;

    int cnt;
    int order = 1;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int num;
        cin >> num;
        
        if(num == order){
            ++order;
        }
        else{
            while(temp.empty() == false && temp.top() == order){
                temp.pop();
                ++order;
            }
            temp.push(num);
        }
    }

    while(temp.empty() == false){
        if(temp.top() == order){
            ++order;
            temp.pop();
        }
        else{
            cout << "Sad";
            return 0;
        }
    }

    cout << "Nice";
}
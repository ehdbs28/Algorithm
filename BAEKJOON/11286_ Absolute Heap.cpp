#include<iostream>
#include<queue>

using namespace std;

struct Absolute
{
    bool operator()(int t, int u){
        if(abs(t) > abs(u)){
            return true;
        }
        else if(abs(t) == abs(u)){
            return u < 0;
        }
        else{
            return false;
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    priority_queue<int, vector<int>, Absolute> heap;
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        int input;
        int answer = 0;
        cin >> input;

        if(input == 0){
            if(!heap.empty()){
                answer = heap.top();
                heap.pop();
            }
            cout << answer << "\n";
        }
        else{
            heap.push(input);
        }
    }
}
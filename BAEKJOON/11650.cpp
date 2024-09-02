#include<iostream>
#include<queue>

using namespace std;

struct pairSort{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first == b.first)
            return a.second > b.second;

        return a.first > b.first;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, pairSort> array;
    int arraySize, firstInput, secondInput;

    cin >> arraySize;

    for(int i = 0; i < arraySize; i++){
        cin >> firstInput >> secondInput;
        array.push({ firstInput, secondInput });
    }

    for(int i = 0; i < arraySize; i++){
        cout << array.top().first << " " << array.top().second << "\n";
        array.pop();
    }
}
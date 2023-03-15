#include<iostream>
#include<set>

using namespace std;

struct CustomGreater{
    bool operator()(pair<int,int> a, pair<int,int> b) const {
        return a.second <= b.second;
    }
};

set<pair<int, int>, CustomGreater> doublePriorityQueue;

void CalculateOper(char operation, int operationNum, int index);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int testCase;
    int operationCount;

    cin >> testCase;

    while(testCase--){
        doublePriorityQueue.clear();

        char operation;
        int operationNum;

        cin >> operationCount;

        for(int i = 0; i < operationCount; i++){
            cin >> operation >> operationNum;
            CalculateOper(operation, operationNum, i);
        }

        if(doublePriorityQueue.empty()){
            cout << "EMPTY" << "\n";
        }
        else{
            cout << (*(--doublePriorityQueue.end())).second << " " << (*doublePriorityQueue.begin()).second << "\n";
        }
    }
}

void CalculateOper(char operation, int operationNum, int index){
    switch(operation){
        case 'I':
            {
                doublePriorityQueue.insert({ index, operationNum });
            }
            break;
        case 'D':
            {
                if(doublePriorityQueue.empty()){
                    return;
                }
                else if(operationNum == 1){
                    doublePriorityQueue.erase(--doublePriorityQueue.end());
                }
                else{
                    doublePriorityQueue.erase(doublePriorityQueue.begin());
                }
            }
            break;
    }
}
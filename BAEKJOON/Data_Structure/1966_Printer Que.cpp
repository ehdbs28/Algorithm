#include<iostream>
#include<queue>

using namespace std;

bool CheckImportance(queue<int> queue){
    int checkNum = queue.front();
    queue.pop();

    for(int i = 0; i < queue.size(); i++){
        int n = queue.front();
        queue.pop();

        if(n > checkNum) return false;
    }
    return true;
}

int main(){
    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        int lenght, index, indexNum, count;
        cin >> lenght >> index;
        queue<int> printQue;
        for(int j = 0; j < lenght; j++){
            int n;
            cin >> n;
            if(j == index) indexNum = n;
            printQue.push(n);
        }

        while(!printQue.empty()){
            if(CheckImportance(printQue)){
                count++;
                if(printQue.front() == indexNum){
                    cout << count << "\n";
                    break;
                }
                printQue.pop();
            }
            else{
                printQue.push(printQue.front());
                printQue.pop();
            }
        }
    }
}
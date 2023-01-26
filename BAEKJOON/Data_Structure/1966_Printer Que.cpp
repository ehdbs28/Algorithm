#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Printer(int arraySize, int index, vector<int> printerQueue){
    vector<int> v = printerQueue;
    sort(v.begin(), v.end());

    while(!printerQueue.empty())
    {
        if(printerQueue.front() == v.back()){ // 이게 제일 큰수
            if(index == 0)
                return (arraySize - printerQueue.size()) + 1;

            printerQueue.erase(printerQueue.begin());
            v.erase(v.begin() + v.size() - 1);
        }
        else{
            printerQueue.push_back(printerQueue.front());
            printerQueue.erase(printerQueue.begin());

            if(index == 0)
                index = printerQueue.size();
            
        }

        index--;
    }
    

    return arraySize;
}

int main(){
    int testcase;
    int result[100];

    cin >> testcase;

    for(int i = 0; i < testcase; i++){
        int arraySize, index;
        vector<int> printerQueue;

        cin >> arraySize >> index;

        for(int j = 0; j < arraySize; j++){
            int input = 0;
            cin >> input;
            printerQueue.push_back(input);
        }

        result[i] = Printer(arraySize, index, printerQueue);
    }

    for(int i = 0; i < testcase; i++)
        cout << result[i] << "\n";
}
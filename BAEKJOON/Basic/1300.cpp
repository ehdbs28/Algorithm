#include<iostream>

using namespace std;

int main(){
    int arraySize;
    int target;

    int start = 1, end, mid;
    int count = 0;

    cin >> arraySize >> target;

    end = target;

    while (true)
    {
        if(end - start <= 1){
            break;
        }

        count = 0;
        mid = (end + start) / 2;

        for(int i = 1; i <= arraySize; i++){
            count += min(mid / i, arraySize);
        }

        if(count < target){
            start = mid;
        }
        else{
            end = mid;
        }
    }

    cout << end;
}   
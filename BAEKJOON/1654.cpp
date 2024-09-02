#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> lines;
    long long haveLineCnt, newLineCnt, input;
    long long start, end, mid, maxNum = 0, count = 0;

    cin >> haveLineCnt >> newLineCnt;

    for(int i = 0; i < haveLineCnt; i++){
        cin >> input;
        maxNum = max(input, maxNum);
        lines.push_back(input);
    }

    start = 1; end = maxNum;

    while(start <= end){
        mid = (start + end) / 2;
        count = 0;

        for(auto line : lines){
            count += line / mid;
        }

        if(count >= newLineCnt){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << end;
}
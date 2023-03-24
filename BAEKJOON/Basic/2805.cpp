#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<long long> trees;
    long long treeCount, treeLenght, input, lenghtSum = 0, start, end, mid, maxNum = 0;

    cin >> treeCount >> treeLenght;

    for(int i = 0; i < treeCount; i++){
        cin >> input;
        maxNum = max(maxNum, input);
        trees.push_back(input);
    }

    start = 0; end = maxNum;

    while(start + 1 < end){
        mid = (start + end) / 2;
        lenghtSum = 0;
        for(auto tree : trees){
            if(tree < mid) continue;
            lenghtSum += tree - mid;
        }

        if(lenghtSum >= treeLenght){
            start = mid;
        }
        else{
            end = mid;
        }
    }

    cout << start;
}
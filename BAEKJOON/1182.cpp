#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void SubsetSum(vector<int> &set, int sum, int i, int target, int &answer){
    if(i >= set.size()){
        return;
    }

    if(sum + set[i] == target){
        ++answer;
    }

    SubsetSum(set, sum + set[i], i + 1, target, answer);
    SubsetSum(set, sum, i + 1, target, answer);
}

int main(){
    vector<int> set;

    int lenght, target;
    int answer = 0;

    cin >> lenght >> target;

    set.resize(lenght);

    for(int i = 0; i < lenght; i++){
        cin >> set[i];
    }

    sort(set.begin(), set.end());

    SubsetSum(set, 0, 0, target, answer);
    cout << answer;
}
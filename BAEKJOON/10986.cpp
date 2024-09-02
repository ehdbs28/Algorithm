#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int arraySize, target, input, answer = 0;
    int array[1001] = {};
    long long prefix_sum = 0;

    cin >> arraySize >> target;

    for(int i = 0; i < arraySize; i++){
        cin >> input;
        prefix_sum += input;
        ++array[prefix_sum % target];
    }

    for(int i = 0; i <= 1000; i++){
        answer += array[i] * (array[i] - 1) / 2;
    }
    answer += array[0];

    cout << answer;
}
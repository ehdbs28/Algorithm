#include<iostream>
#include<vector>

using namespace std;

int solution(int n);

int main(){
    cout << solution(3);
}

int solution(int n){
    vector<int> fibonacciNumbers = {0, 1};
    int answer = 0;

    for(int i = 0; i < n; i++){
        int back = fibonacciNumbers[fibonacciNumbers.size() - 2];
        int front = fibonacciNumbers.back();

        fibonacciNumbers.push_back((back + front) % 1234567);
    }

    answer = fibonacciNumbers[n];
    return answer;
}
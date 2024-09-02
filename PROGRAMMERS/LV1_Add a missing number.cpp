#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int> numbers);

int main(){
    vector<int> test = {1,2,3,4,6,7,8,0};
    cout << solution(test);
}

int solution(vector<int> numbers){
    int answer = 0;

    sort(numbers.begin(), numbers.end());

    for(int i = 0; i < 10; i++){
        if(numbers.front() == i)
            numbers.erase(numbers.begin());
        else{
            answer += i;
            continue;
        }
    }

    return answer;
}
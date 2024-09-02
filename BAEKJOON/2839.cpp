#include<iostream>
#include<climits>

using namespace std;

int main(){
    int target, temp;
    int count = 0;
    int tempCount = 0;
    int answer = INT_MAX;

    cin >> target;


    while(target / 3 > 0){
        temp = target;
        tempCount = 0;

        while(temp / 3 > 0){
            temp -= 3;
            ++tempCount;
        }

        if(temp == 0)
            answer = min(answer, (count + tempCount));

        target -= 5;
        ++count;

        if(target == 0){
            answer = min(answer, count);
        }
    }

    if(answer == INT_MAX)
        cout << -1;
    else
        cout << answer;
}
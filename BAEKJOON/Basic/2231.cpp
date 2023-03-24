#include<iostream>
#include<set>

using namespace std;

int GetSum(int input);

int main(){
    set<int> constructors;
    int input, sum = 0;

    cin >> input;

    for(int i = input; i > 0; i--){
        if(i + GetSum(i) == input)
            constructors.insert(i);
    }

    cout << *constructors.begin();
}

int GetSum(int input){
    int sum = 0;

    while(input > 0){
        sum += input % 10;
        input /= 10;
    }

    return sum;
}
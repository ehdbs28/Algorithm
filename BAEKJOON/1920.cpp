#include<iostream>
#include<set>

using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);

    set<int> numbers;
    int count1, count2, input = 0;

    cin >> count1;

    for(int i = 0; i < count1; i++){
        cin >> input;
        numbers.insert(input);
    }

    cin >> count2;

    for(int i = 0; i < count2; i++){
        cin >> input;
        cout << (numbers.count(input) == 1 ? 1 : 0) << "\n";
    }
}
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string input1, input2;

    cin >> input1 >> input2;

    reverse(input1.begin(), input1.end());
    reverse(input2.begin(), input2.end());

    cout << max(stoi(input1), stoi(input2));
}
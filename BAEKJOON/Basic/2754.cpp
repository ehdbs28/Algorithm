#include<iostream>
#include<string>

using namespace std;

int main(){
    cout.precision(1);
    cout << fixed;
    string input;

    cin >> input;

    if(input[0] == 'F'){
        cout << 0.0;
        return 0;
    }

    float score = 4.f - (input[0] - 'A');

    if(input[1] == '+')
        score += 0.3;
    else if(input[1] == '0')
        score += 0;
    else
        score -= 0.3;

    cout << score;
}
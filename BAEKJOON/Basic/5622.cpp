#include<iostream>
#include<string>

using namespace std;

string Dial[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

int GetNum(char ch);

int main(){
    string input;
    int answer = 0;

    cin >> input;

    for(char ch : input)
        answer += GetNum(ch);

    cout << answer;
}

int GetNum(char ch){
    for(int i = 0; i < 8; i++){
        if(Dial[i].find(ch) != string::npos){
            return i + 3; 
        }
    }

    return 0;
}
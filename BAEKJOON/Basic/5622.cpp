#include<iostream>
#include<string>

using namespace std;

string Dial[] = { "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ" };

int GetNum(char ch);

int main(){
    string input;
    int answer = 0;

    cin >> input;

    for(char ch : input){
        int num = GetNum(ch);
        answer += 2 + (num - 1);
    }

    cout << answer;
}

int GetNum(char ch){
    for(int i = 0; i < 8; i++){
        if(Dial[i].find(ch) != string::npos){
            return i + 2; 
        }
    }

    return 0;
}
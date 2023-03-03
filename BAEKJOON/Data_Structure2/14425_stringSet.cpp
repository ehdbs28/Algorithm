#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int stringSetLenght;
    int answerLenght;
    int answer = 0;

    cin >> stringSetLenght >> answerLenght;

    map<string, int> stringSet;

    for(int i = 0; i < stringSetLenght; i++){
        string input;
        cin >> input;
        stringSet.insert({input, i});
    }

    for(int i = 0; i < answerLenght; i++){
        string input;
        cin >> input;

        if(stringSet.find(input) != stringSet.end())
            ++answer;
    } 

    cout << answer;
}
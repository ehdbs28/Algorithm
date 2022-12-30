#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int stringSetLenght;
    int answerLenght;
    int answer = 0;

    cin >> stringSetLenght >> answerLenght;

    string* stringSet = new string[stringSetLenght];

    for(int i = 0; i < stringSetLenght; i++){
        cin >> stringSet[i];
    }

    for(int i = 0; i < answerLenght; i++){
        string input;
        cin >> input;

        for(int j = 0; j < stringSetLenght; j++){   
            if(stringSet[j] == input)
                answer++;
        }
    } 

    cout << answer;
}
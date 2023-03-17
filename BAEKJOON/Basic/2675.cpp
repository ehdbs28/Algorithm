#include<iostream>
#include<string>

using namespace std;

int main(){
    int testCase;
    cin >> testCase;

    while(testCase--){
        string input;
        int loopCount;

        cin >> loopCount >> input;

        for(int i = 0; i < input.length(); i++){
            for(int j = 0; j < loopCount; j++)
                cout << input[i];
        }
        cout << "\n";
    }
}
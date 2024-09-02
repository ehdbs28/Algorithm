#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    int answer = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        unordered_map<int, int> chars;
        bool correct = true;
        string input;

        cin >> input;

        for(int i = 0; i < input.length(); i++){
            if(chars[input[i]] == 0 || chars[input[i]] == i){
                chars[input[i]] = i + 1;
            }
            else{
                correct = false;
                break;
            }
        }

        if(correct)
            ++answer;
    }

    cout << answer;
}
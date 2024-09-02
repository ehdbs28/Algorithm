#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

char GetAlpha(string* input);

int main(){
    string input;
    cin >> input;

    for(int i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);
        
    cout << GetAlpha(&input);
}

char GetAlpha(string* input){
    unordered_map<char, int> map;
    int temp = 0;
    char best = '?';

    for(char ch : *input){
        if(map.count(ch) == 0){
            map.insert({ ch, 1 });
        }
        else{
            map.at(ch)++;
        }
    }

    for(auto value : map){
        if(temp != 0){
            if(temp < value.second){
                temp = value.second;
                best = value.first;
            }
            else if(temp == value.second)
                best = '?';
        }
        else{
            temp = value.second;
            best = value.first;
        }
    }

    return best;
}
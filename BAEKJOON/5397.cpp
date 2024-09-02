#include<iostream>
#include<list>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int testcase;

    cin >> testcase;

    while(testcase--){
        list<char> password;
        string input;
        list<char>::iterator cursor = password.begin();

        cin >> input;

        for(int i = 0; i < input.length(); i++){
            if(input[i] == '<'){
                if(cursor != password.begin())
                    --cursor;
            }
            else if(input[i] == '>'){
                if(cursor != password.end())
                    ++cursor;
            }
            else if(input[i] == '-'){
                if(cursor != password.begin())
                    cursor = password.erase(--cursor);
            }
            else{
                password.insert(cursor, input[i]);
            }
        }

        for(auto ch : password){
            cout << ch;
        }
        cout << "\n";
    }
}
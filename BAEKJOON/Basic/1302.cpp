#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    map<string, int> soldBook;

    int cnt;
    int maxCnt = 0;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        string bookName;
        cin >> bookName;
        ++soldBook[bookName];
        maxCnt = max(maxCnt, soldBook[bookName]);
    }

    for(auto bookInfo : soldBook){
        if(bookInfo.second == maxCnt){
            cout << bookInfo.first;
            break;
        }
    }
}
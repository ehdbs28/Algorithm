#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);

    map<string, int> people;

    string input;

    int noSeeCount;
    int noHearCount;

    int count = 0;

    cin >> noSeeCount >> noHearCount;

    for(int i = 0; i < noSeeCount + noHearCount; i++){
        cin >> input;
        ++people[input];
        if(people[input] >= 2)
            ++count;
    }

    cout << count << "\n";
    for(auto person : people){
        if(person.second >= 2)
            cout << person.first << "\n";
    }
}
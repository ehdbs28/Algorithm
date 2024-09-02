#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, string> map;
    int count, answerCount;
    string site, password;

    cin >> count >> answerCount;

    for(int i = 0; i < count; i++){
        cin >> site >> password;
        map[site] = password;
    }

    for(int i = 0; i < answerCount; i++){
        cin >> site;
        cout << map[site] << "\n";
    }
}
#include<iostream>
#include<string>
#include<map>

using namespace std;

bool IsOnlyAlphabet(string value);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> pokemonMap;
    string name[100000];

    for(int i = 0; i < n; i++){ //insert PokeDex
        string poketmonName = "";
        cin >> poketmonName;

        pokemonMap.insert({poketmonName, i});
        name[i] = poketmonName;
    }

    for(int i = 0; i < m; i++){ //insert Problem
        string problemInput;

        cin >> problemInput;
        if(isdigit(problemInput[0])){ //is number
            cout << name[stoi(problemInput) - 1] << "\n";
        }
        else{
            cout << pokemonMap.at(problemInput) + 1 << "\n";
        }
    }
}
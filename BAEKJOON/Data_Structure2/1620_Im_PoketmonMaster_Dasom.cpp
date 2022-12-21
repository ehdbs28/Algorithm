#include<iostream>
#include<string>
#include<map>

using namespace std;

bool IsOnlyAlphabet(string value);

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    map<int, string> PokeDex;

    cin >> n >> m;

    for(int i = 0; i < n; i++){ //insert PokeDex
        string poketmonName = "";
        cin >> poketmonName;

        PokeDex.insert({i, poketmonName});
    }

    for(int i = 0; i < m; i++){ //insert Problem
        string problemInput;

        cin >> problemInput;
        if(IsOnlyAlphabet(problemInput)){
            for(auto const& pokemon : PokeDex){
                if(pokemon.second.compare(problemInput) == 0){
                    cout << pokemon.first << "\n";
                }
            }
        }
        else{
            cout << PokeDex.at(stoi(problemInput) - 1) << "\n";
        }
    }
}

bool IsOnlyAlphabet(string value){
    for(char ch : value){
        if(!isalpha(ch))
            return false;
    }

    return true;
}
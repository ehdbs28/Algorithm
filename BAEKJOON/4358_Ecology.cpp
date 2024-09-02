#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    cout.tie(NULL); cin.tie(NULL);

    cout << fixed;
    cout.precision(4);

    map<string, double> ecoSystem;

    int wood_count = 0;

    for(wood_count = 0; wood_count < 1000000; wood_count++){
        string wood;
        getline(cin, wood);

        if(wood == "") break;

        if(ecoSystem.find(wood) != ecoSystem.end()){
            ++ecoSystem[wood];
        }
        else{
            ecoSystem.insert({wood, 1});
        }
        wood.clear();
    }

    for(auto wood : ecoSystem){
        cout << wood.first << " " << wood.second / wood_count * 100 << "\n";
    }
}
#include<iostream>
#include<map>

using namespace std;

int main(){
    map<string, bool, greater<string>> people;

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        string enter;

        cin >> name >> enter;
        
        people[name] = (enter == "enter" ? true : false);
    }

    for(auto p : people){
        if(p.second){
            cout << p.first << "\n";
        }
    }
}
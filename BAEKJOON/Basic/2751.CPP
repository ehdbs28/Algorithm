#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> array;
    int count, input;

    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> input;
        array.insert(input);
    }

    for(auto i : array){
        cout << i << "\n";
    }
}
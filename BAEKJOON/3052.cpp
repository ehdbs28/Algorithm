#include<iostream>
#include<set>

using namespace std;

int main(){
    int num;
    set<int> remains;

    for(int i = 0; i < 10; i++){
        cin >> num;
        remains.insert(num % 42);
    }

    cout << remains.size();
}
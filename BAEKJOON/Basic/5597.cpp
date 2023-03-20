#include<iostream>

using namespace std;

int main(){
    bool students[30] = {};
    int num;

    for(int i = 0; i < 28; i++){
        cin >> num;
        students[num - 1] = true;
    }

    for(int i = 0; i < 30; i++){
        if(students[i])
            continue;
        else
            cout << i + 1 << "\n";
    }
}
#include <iostream>

using namespace std;

void setStar(int cnt){
    if(cnt <= 0){
        return;
    }

    for(int i = 0; i < cnt; i++){
        cout << "* ";
    }
    cout << "\n";
    setStar(cnt - 1);
    for(int i = 0; i < cnt; i++){
        cout << "* ";
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;
    setStar(n);
}
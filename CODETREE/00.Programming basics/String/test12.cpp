#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;
    cin >> a >> b;

    for(int i = 0; i < a.length();){
        if(a[i] >= 'a' && a[i] <= 'z'){
            a.erase(i, 1);
        }
        else{
            i++;
        }
    }

    for(int i = 0; i < b.length();){
        if(b[i] >= 'a' && b[i] <= 'z'){
            b.erase(i, 1);
        }
        else{
            i++;
        }
    }

    cout << std::stoi(a) + std::stoi(b);
}
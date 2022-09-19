#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> bv = { b[2] - 48, b[1] - 48, b[0] - 48 };

    cout << stoi(a) * bv[0] << endl;
    cout << stoi(a) * bv[1] << endl;
    cout << stoi(a) * bv[2] << endl;
    cout << stoi(a) * bv[0] + stoi(a) * (bv[1] * 10) + stoi(a) * (bv[2] * 100);
}
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool isBrokenNum(int);

vector<int> dp;
vector<int> broken(10, false);

int main(){
    int n, m;
    int input;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> input;
        broken[input] = true;
    }

    int minimum = abs(n - 100);
    for(int i = 0; i <= 1000000; i++){
        if(isBrokenNum(i)){
            int temp = abs(n - i) + to_string(i).length();
            minimum = min(minimum, temp);
        }
    }

    cout << minimum;
}

bool isBrokenNum(int current){
    string s = to_string(current);

    for(int i = 0; i < s.length(); i++){
        if(broken[s[i] - '0'])
            return false;
    }

    return true;
}
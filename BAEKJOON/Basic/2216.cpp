#include<iostream>
#include<climits>

//#define MAX

using namespace std;

int dp[3001][3001] = {};
int n1, n2, n3;
string a, b;

int sol(int i, int j){
    int& elem = dp[i][j];

    if(elem != INT_MAX)
        return elem;

    elem = 0;

    if(i == a.length() && j == b.length())
        return elem;

    elem = INT_MIN;

    if(i < a.length() && j < b.length()){
        if(a[i] == b[j]){
            elem = max(elem, sol(i + 1, j + 1) + n1);
        }
        else{
            elem = max(elem, sol(i + 1, j + 1) + n3);
        }
    }

    if(i < a.length()){
        elem = max(elem, sol(i + 1, j) + n2);
    }

    if(j < b.length()){
        elem = max(elem, sol(i, j + 1) + n2);
    }

    return elem;
}

int main(){
    cin >> n1 >> n2 >> n3 >> a >> b;

    for(auto& arr : dp){
        for(int& elem : arr){
            elem = INT_MAX;
        }
    }

    cout << sol(0, 0);
}
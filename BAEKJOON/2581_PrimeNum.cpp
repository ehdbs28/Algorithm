#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    vector<int> primeNums;

    int min, max, sum = 0;

    cin >> min >> max;

    for(int i = min; i <= max; i++){
        for(int j = 2; j <= i; j++){
            if(i % j == 0){
                if(i == j) primeNums.push_back(i);
                break;
            }
        }
    }

    for(int n : primeNums){
        sum += n;
    }
    
    if(primeNums.empty()) cout << -1;
    else cout << sum << endl << primeNums.front();
}
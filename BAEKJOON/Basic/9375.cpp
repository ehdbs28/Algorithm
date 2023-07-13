#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main(){
    int testCase;
    
    cin >> testCase;

    while(testCase--){
        map<string, int> m;
        int n;
        int answer = 1;

        cin >> n;

        for(int i = 0; i < n; i++){
            string type;
            string value;
            cin >> value >> type;
            m[type]++;
        }

        for(auto pair : m){
            answer *= pair.second + 1;
        }        

        cout << answer - 1<< "\n";
    }
}
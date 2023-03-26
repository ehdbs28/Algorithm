#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    unordered_map<int, int> numbers;

    int n, m, input;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        
        numbers.insert({input, 0});
        ++numbers[input];
    }

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> input;

        cout << numbers[input] << " ";
    }
}
#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int prefixNum[100002] = {};

    int n, m;
    int input, i, j;

    cin >> n >> m;

    for(i = 0; i < n; i++){
        cin >> input;
        prefixNum[i + 1] = prefixNum[i] + input;
    }

    for(int k = 0; k < m; k++){
        cin >> i >> j;
        cout << (prefixNum[j] - prefixNum[i - 1]) << "\n";
    }
}
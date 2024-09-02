#include<iostream>

using namespace std;

int main(){
    int n, k;
    int a[10] = {};
    int answer = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 9; i >= 0; i--){
        if(a[i] > k || a[i] == 0)
            continue;

        answer += k / a[i];
        k %= a[i];
    }

    cout << answer;
}
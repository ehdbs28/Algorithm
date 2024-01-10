#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int* mod = new int[b];

    while(a > 1){
        mod[a % b]++;
        a /= b;
    }

    int ans = 0;
    for(int i = 0; i < b; i++){
        ans += mod[i] * mod[i];
    }

    cout << ans;
}
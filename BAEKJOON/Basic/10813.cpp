#include<iostream>

using namespace std;

int main(){
    int baskets[100];
    int n, m, idx_1, idx_2;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        baskets[i] = i + 1;
    }

    while(m--){
        cin >> idx_1 >> idx_2;
        swap(baskets[idx_1 - 1], baskets[idx_2 - 1]);
    }

    for(int i = 0; i < n; i++){
        cout << baskets[i] << " ";
    }
}
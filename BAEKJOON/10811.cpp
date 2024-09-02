#include<iostream>

using namespace std;

int main(){
    int baskets[100] = {};
    int n, m, idx_1, idx_2;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        baskets[i] = i + 1;
    }

    while(m--){
        cin >> idx_1 >> idx_2;

        for(int i  = 0; i < idx_2 - idx_1; i++){
            int swapIndex_1 = (idx_1 - 1) + i;
            int swapIndex_2 = (idx_2 - 1) - i;
            if(swapIndex_1 >= swapIndex_2) continue;

            swap(baskets[swapIndex_1], baskets[swapIndex_2]);
        }
    }

    for(int i = 0; i < n; i++){
        cout << baskets[i] << " ";
    }
}
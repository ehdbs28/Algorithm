#include<iostream>

using namespace std;

int main(){
    int basket[100] = {};
    int n = 0, m = 0, idx_1, idx_2, ballNum;

    cin >> n >> m;

    while(m--){
        cin >> idx_1 >> idx_2 >> ballNum;

        for(int i = idx_1 - 1; i < idx_2; i++){
            basket[i] = ballNum;
        }
    }

    for(int i = 0; i < n; i++){
        cout << basket[i] << " ";
    }
}

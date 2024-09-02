#include<iostream>

using namespace std;

int n;
int m;

int arr[9] = {};
bool check[9] = {};

void func(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            arr[cnt] = i;
            check[i] = true;
            func(cnt + 1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    func(0);
}
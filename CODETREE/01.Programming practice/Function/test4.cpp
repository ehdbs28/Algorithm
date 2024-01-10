#include <iostream>

using namespace std;

int n;
int m;
int* arr;

int getSum(int s, int e){
    int sum = 0;
    for(int i = s - 1; i < e; i++){
        sum += arr[i];
    }
    return sum;
}

int main() {
    cin >> n >> m;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << getSum(s, e) << "\n";
    }
}
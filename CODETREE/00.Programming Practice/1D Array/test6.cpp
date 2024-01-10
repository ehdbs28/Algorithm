#include <iostream>

using namespace std;

int main() {
    int n;
    int ans = 100;
    int* arr = new int[n];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i > 0){
            if(ans > arr[i] - arr[i - 1]){
                ans = arr[i] - arr[i - 1];
            }
        }
    }

    cout << ans;
}
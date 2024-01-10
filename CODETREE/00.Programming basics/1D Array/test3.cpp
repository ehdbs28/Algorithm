#include <iostream>

using namespace std;

int main() {
    int arr[10];

    cin >> arr[0];
    cin >> arr[1];

    for(int i = 0; i < 10; i++){
        if(i >= 2){
            arr[i] = arr[i - 1] + arr[i - 2] * 2;
        }
        cout << arr[i] << " ";
    }
}
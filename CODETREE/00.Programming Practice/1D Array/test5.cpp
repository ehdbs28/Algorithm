#include <iostream>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        if(num == 2){
            cnt++;

            if(cnt >= 3){
                cout << i + 1;
                break;
            }
        }
    }
}
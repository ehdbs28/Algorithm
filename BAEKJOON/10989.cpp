#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int nums[10001] = {};
    int count, input;

    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> input;
        ++nums[input];
    }

    for(int i = 0; i < 10001; i++){
        if(!nums[i]) continue;

        for(int j = 0; j < nums[i]; j++){
            cout << i << "\n";
        }
    }
}
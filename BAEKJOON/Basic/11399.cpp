#include<iostream>

using namespace std;

int main(){
    int time[1001] = {};
    int cnt;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        cin >> time[i];
    }

    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < cnt - 1 - i; j++){
            if(time[j] > time[j + 1]){
                int temp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < cnt; i++){
        for(int j = 0; j <= i; j++){
            time[cnt] += time[j];
        }
    }

    cout << time[cnt];
}
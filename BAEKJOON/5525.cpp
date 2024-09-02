#include <iostream>

using namespace std;

int main(){
    int n;
    int m;

    int answer = 0;
    int temp = 0;

    bool isStart = false;

    string s;

    cin >> n >> m >> s;

    for(int i = 0; i < m - 1; i++){
        if(isStart){
            if(s[i] == 'O' && s[i + 1] == 'I'){
                ++temp;
                ++i;
            }
            else{
                isStart = false;
                if(temp >= n){
                    answer += temp - (n - 1);
                }
                temp = 0;
            }
        }

        if(!isStart && s[i] == 'I')
            isStart = true;
    }

    if(isStart && temp >= n)
        answer += temp - (n - 1);

    cout << answer;
}

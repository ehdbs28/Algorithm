#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Get_LCM(long long a, long long b){
    long long remain = a % b;

    if(remain == 0){
        return b;
    }
    else{
        return Get_LCM(b, remain);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        long long a, b = 0;
        cin >> a >> b;

        if(a < b) swap(a, b);

        cout << a * b / Get_LCM(a, b) << "\n";
    }

    return 0;
}
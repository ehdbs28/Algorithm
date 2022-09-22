#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Get_GCD(int a, int b){
    int remain = a % b;

    if(remain == 0){
        return b;
    }
    else{
        return Get_GCD(b, remain);
    }
}

int main(){
    int cnt;
    cin >> cnt;

    int *LCM = new int[cnt];
    for(int i = 0; i < cnt; i++){
        int a, b = 0;
        int GCD = 0;

        cin >> a >> b;
        if(a < b) swap(a, b);

        GCD = Get_GCD(a, b);
        
        LCM[i] = a * b / GCD;
    }

    for(int i = 0; i < cnt; i++){
        cout << LCM[i] << endl;
    }

    return 0;
}
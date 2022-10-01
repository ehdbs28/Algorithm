#include<iostream>

using namespace std;

int Get_GCD(int a, int b){
    if(b > a) swap(a, b);
    if(b == 0) return b;
    
    int remain = a % b;

    if(remain == 0){
        return b;
    }
    else{
        return Get_GCD(b, remain);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int lenght;
    double x;
    double hap = 0, count = 0;
    cin >> lenght;
    double* array = new double[lenght];

    for(int i = 0; i < lenght; i++){
        double n;
        cin >> n;
        array[i] = n;
    }
    cin >> x;
    for(int i = 0; i < lenght; i++){
        if(Get_GCD(array[i], x) == 1){
            hap += array[i];
            count++;
        }
    }

    cout << (int)(hap / count);
}
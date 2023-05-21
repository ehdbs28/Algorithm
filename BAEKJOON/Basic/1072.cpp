#include<iostream>

using namespace std;

int main(){
    long long x;
    long long y;
    long long z;

    cin >> x >> y;

    z = (y * 100) / x;

    int left = 0;
    int right = 1000000000;
    int mid;

    if(z >= 99){
        cout << -1;
        return 0;
    }

    int result = -1;
    while(left <= right){
        mid = (left + right) / 2;
        
        long long zTemp = ((y + mid) * 100) / (x + mid);
        if(z < zTemp){
            right = mid - 1;
        }
        else{
            left = mid + 1;
            result = left;
        }  
    }

    cout << result;
}
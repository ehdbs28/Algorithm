#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n;
    int l;
    int w;
    int h;

    cin >> n >> l >> w >> h;

    double left = 0;
    double right = 1000000000;
    double mid;

    for(int i = 0; i < 100; i++){
        mid = (left + right) / 2.f;
        long long cnt = (long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid);

        if(cnt >= n){
            left = mid;
        }
        else{
            right = mid;
        }
    }

    printf("%.10lf", left);
}
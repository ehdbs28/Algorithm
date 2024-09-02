#include<iostream>

using namespace std;

int main(){
    long long upper, down, max;
    long long day = 0;

    cin >> upper >> down >> max;  

    day = (max - down) / (upper - down);

    if(max - down > day * (upper - down))
        ++day;
    
    cout << day;
}
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int h, m;
    cin >> h >> m;

    if(h == 0) h = 24;

    m += h * 60;
    m -= 45;

    h = 0;
    while(m >= 60){
        m -= 60;
        h++;
    }

    if(h == 24) h = 0;

    cout << h << " " << m;
}
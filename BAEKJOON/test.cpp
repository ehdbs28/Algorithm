#include<iostream>
#include<string>
#include<vector>

using namespace std;

void TimeSet(int h, int m, int t);

int main(){
    int h, m, t;
    cin >> h >> m >> t;

    TimeSet(h, m, t);
}

void TimeSet(int h, int m, int t){
    if(h == 0) h = 24;

    m += h * 60;
    m += t;

    h = 0;
    while(m >= 60){
        m -= 60;
        h++;
    }

    if(h >= 24) h -= 24;

    cout << h << " " << m;
}
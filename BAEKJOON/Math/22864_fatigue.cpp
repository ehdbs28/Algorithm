#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int a, b, c, m;

    int day = 24;
    int fatigue  = 0;
    int workAmount = 0;

    cin >> a >> b >> c >> m;

    while (day > 0)
    {
        fatigue += a;

        if(fatigue <= m){
            workAmount += b;
        }
        else{
            fatigue -= a;
            fatigue -= c;

            if(fatigue < 0) fatigue = 0;
        }

        day--;
    }
    
    cout << workAmount;
}
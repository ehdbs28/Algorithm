#include <iostream>

using namespace std;

bool isDate(int y, int m, int d){
    if(m == 2){
        if(y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)){
            if(d > 29){
                return false;
            }
        }
        else{
            if(d > 28){
                return false;
            }
        }
    }
    else{
        if(m > 7){
            if(d > (m % 2 == 0 ? 31 : 30)){
                return false;
            }
        }
        else{
            if(d > (m % 2 == 0 ? 30 : 31)){
                return false;
            }
        }
    }

    return true;
}

string getSeason(int m){
    string season;

    switch(m){
        case 1:
        case 2:
            season = "Winter";
            break;
        case 3:
        case 4:
        case 5:
            season = "Spring";
            break;
        case 6:
        case 7:
        case 8:
            season = "Summer";
            break;
        case 9:
        case 10:
        case 11:
            season = "Fall";
            break;
        case 12:
            season = "Winter";
            break;
    }

    return season;
}

int main() {
    int y, m, d;
    cin >> y >> m >> d;

    if(isDate(y, m, d)){
        cout << getSeason(m);
    }
    else{
        cout << -1;
    }
}
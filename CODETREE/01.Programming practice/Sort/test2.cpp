#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct info{
    string date;
    string day;
    string weather;

    bool operator()(const info& a, const info& b){
        return a.date < b.date;
    }
};

int main() {
    int n;
    cin >> n;

    vector<info> rain;

    for(int i = 0; i < n; i++){
        string date, day, weather;
        cin >> date >> day >> weather;
        if(weather == "Rain"){
            rain.push_back(info{date, day, weather});
        }
    }

    sort(rain.begin(), rain.end(), info());
    cout << rain[0].date << " " << rain[0].day << " " << rain[0].weather;
}
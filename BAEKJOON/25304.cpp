#include<iostream>
#include<string>
#include<vector>

using namespace std;

int Money(int cnt, vector<int> prices, vector<int> counts);

int main(){
    vector<int> prices;
    vector<int> counts;
    int totalMoney = 0, currentMoney = 0, cnt = 0;
    cin >> totalMoney >> cnt; 

    for(int i = 0; i < cnt; i++){
        int price, count;
        cin >> price >> count;
        prices.push_back(price);
        counts.push_back(count);
    }

    currentMoney = Money(cnt, prices, counts);

    cout << (totalMoney == currentMoney ? "Yes" : "No");
}

int Money(int cnt, vector<int> prices, vector<int> counts){
    int currentMoney = 0;
    for(int i = 0; i < cnt; i++){
        currentMoney += (prices[i] * counts[i]);
    }

    return currentMoney;
}
#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> dp;

    int lenght;
    int num;

    cin >> lenght;

    for(int i = 0; i < lenght; i++){
        cin >> num;

        if(dp.empty() || dp.back() < num){
            dp.push_back(num);
        }
        else{
            *lower_bound(dp.begin(), dp.end(), num) = num;
        }
    }

    cout << dp.size();
}
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v;

    cin >> n;

    if(n == 0){
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    int except = (int)round((float)n * 15 / 100.0f);
    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = except; i < n - except; i++){
        sum += v[i];
    }

    cout << (int)round((float)sum / (float)(n - except * 2));
}
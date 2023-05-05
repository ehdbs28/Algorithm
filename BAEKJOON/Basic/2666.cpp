#include<iostream>
#include<cstring>

using namespace std;

// open1과 open2가 열려있을 때 index를 열기 위한 최소 값 구하기
int count(int index, int open1, int open2, int maxIndex, int dp[21][21][21], int order[21]){
    if(index >= maxIndex)
        return 0;

    int result = dp[index][open1][open2];

    if(result > -1)
        return result;

    int target = order[index];

    dp[index][open1][open2] = min(
        abs(open1 - target) + count(index + 1, target, open2, maxIndex, dp, order),
        abs(open2 - target) + count(index + 1, open1, target, maxIndex, dp, order));

    return dp[index][open1][open2];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 

    int n, t;
    int open1, open2;

    int order[21] = {};
    int dp[21][21][21];
    memset(dp, -1, sizeof(dp));

    cin >> n >> open1 >> open2 >> t;

    for(int i = 0; i < t; i++){
        cin >> order[i];
    }

    cout << count(0, open1, open2, t, dp, order);
}
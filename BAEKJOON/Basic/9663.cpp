#include<iostream>
#include<cmath>

using namespace std;

int n;
int cols[15] = {};
int cnt = 0;

bool check(int r){
    for(int i = 0; i < r; i++){
        // 같은 열인지 검사
        if(cols[r] == cols[i])
            return false;

        // 대각선 검사
        if(abs(r - i) == abs(cols[r] - cols[i]))
            return false;
    }

    return true;
}

void FindQueen(int r){
    if(r == n){
        ++cnt;
        return;
    }

    for(int i = 0; i < n; i++){
        cols[r] = i;

        if(check(r)){
            FindQueen(r + 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    FindQueen(0);

    cout << cnt;
}
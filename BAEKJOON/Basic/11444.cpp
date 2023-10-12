#include<iostream>
#include<vector>

#define MOD 1000000007

using namespace std;

typedef vector<vector<long long>> matrix;

matrix multiply(matrix& a, matrix& b){
    matrix c = { { 0, 0 }, { 0, 0 } };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }

    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n;
    cin >> n;

    matrix ans = { { 1, 0 }, { 0, 1 } };
    matrix a = { { 1, 1 }, { 1, 0 } };

    while(n > 0){
        if(n % 2 == 1){
            ans = multiply(ans, a);
        }

        a = multiply(a, a);
        n /= 2;
    }

    cout << ans[0][1];
}
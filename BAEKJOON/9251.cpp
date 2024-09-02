#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int lcs[1001][1001] = {};
    int ans = 0;

    string a;
    string b;

    cin >> a >> b;

    for(int i = 0; i <= b.length(); i++){
        for(int j = 0; j <= a.length(); j++){
            if(i == 0 || j == 0){
                lcs[i][j] = 0;
            }
            else if(a[j - 1] == b[i - 1]){
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else{
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }

            ans = max(ans, lcs[i][j]);
        }
    }

    cout << ans;
}
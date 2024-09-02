#include<iostream>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    bool result = true;
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int cnt;
        int last = INT_MAX;

        cin >> cnt;

        for(int j = 0; j < cnt; j++){
            int input;
            cin >> input;

            if(input > last){
                result = false;
            }

            last = input;
        }
    }

    cout << (result ? "Yes" : "No");
}
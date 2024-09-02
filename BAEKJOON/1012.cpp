#include<iostream>
#include<cstring>

using namespace std;

void check(int arr[50][50], int _x, int _y){
    for(int y = -1; y <= 1; y++){
        for(int x = -1; x <= 1; x++){
            if(x == 0 || y == 0){
                if(_x + x < 0 || _y + y < 0 || _x + x >= 50 || _y + y >= 50){
                    continue;
                }

                if(arr[_y + y][_x + x] == 1){
                    arr[_y + y][_x + x] = 2;
                    check(arr, _x + x, _y + y);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int arr[50][50] = {};
    
    int t;
    int n;
    int m;
    int k;

    int answer = 0;

    cin >> t;

    while(t--){
        memset(arr, 0, sizeof(arr));
        answer = 0;

        cin >> n >> m >> k;

        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(arr[y][x] == 1){
                    arr[y][x] = 2;
                    ++answer;
                    check(arr, x, y);
                }
            }
        }

        cout << answer << "\n";
    }
}
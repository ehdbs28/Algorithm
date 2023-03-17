#include<iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int answer[100][100];

    for(int i = 0; i < 2; i++){
        for(int row = 0; row < n; row++){
            for(int column = 0; column < m; column++){
                int num;
                cin >> num;
                answer[row][column] += num;
            }
        }
    }

    for(int row = 0; row < n; row++){
        for(int column = 0; column < m; column++){
            cout << answer[row][column];
            if(column < m - 1) cout << " ";
        }

        if(row < n - 1) cout << "\n";
    }
}
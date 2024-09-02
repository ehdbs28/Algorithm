#include<iostream>
#include<stack>

using namespace std;

int main(){
    int count, answer = 0;
    bool canvas[100][100] = {};

    cin >> count;

    for(int i = 0; i < count; i++){
        int pos1, pos2;
        cin >> pos1 >> pos2;

        for(int column = pos2 - 1; column < pos2 + 9; column++){
            for(int row = pos1 - 1; row < pos1 + 9; row++){
                if(!canvas[column][row]){
                    canvas[column][row] = true;
                    ++answer;
                }
            }
        }
    }

    cout << answer;
}
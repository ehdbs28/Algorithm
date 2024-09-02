#include<iostream>
#include<string>
#include<queue>

using namespace std;

enum Color{
    BLACK = 66,
    WHITE = 87
};

int GetCount(string*, int, int, Color);

int main(){
    priority_queue<int, vector<int>, greater<int>> counts;
    string board[50] = {}, input;
    int height, width;

    cin >> height >> width;

    for(int i = 0; i < height; i++){
        cin >> input;
        board[i] = input;
    }

    for(int y = 0; y < height - 7; y++){
        for(int x = 0; x < width - 7; x++){
            counts.push(GetCount(board, x, y, BLACK));
            counts.push(GetCount(board, x, y, WHITE));
        }
    }

    cout << counts.top();
}

int GetCount(string* board, int start_x, int start_y, Color color){
    int startIndex = (start_x % 2 != 0);
    int count = 0, reverseCount = 0;

    for(int y = start_y; y < start_y + 8; y++){
        for(int x = start_x; x < start_x + 8; x++){
            if(x % 2 == startIndex){
                if(board[y][x] != color)
                    ++count;
            }
            else{
                if(board[y][x] == color)
                    ++count;
            }
        }
        color = (color == BLACK ? WHITE : BLACK);
    }

    for(int y = start_y + 7; y >= start_y; y--){
        for(int x = start_x + 7; x >= start_x; x--){
            if(x % 2 != startIndex){
                if(board[y][x] != color)
                    ++reverseCount;
            }
            else{
                if(board[y][x] == color)
                    ++reverseCount;
            }
        }
        color = (color == BLACK ? WHITE : BLACK);
    }

    return min(count, reverseCount);
}
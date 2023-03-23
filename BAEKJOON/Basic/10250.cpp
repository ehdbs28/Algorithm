#include<iostream>

using namespace std;

int GetRoomNumber(int h, int w, int order);

int main(){
    int h, w, order, testCase;

    cin >> testCase;

    while (testCase--)
    {
        cin >> h >> w >> order;
        cout << GetRoomNumber(w, h, order) << "\n";
    }
    
}

int GetRoomNumber(int w, int h, int order){
    int room, floor;

    for(int i = 0; i < w; i++){
        room = i + 1;
        for(int j = 0; j < h; j++){
            floor = j + 1;
            --order;
            if(order == 0)
                return floor * 100 + room;
        }
    }
}
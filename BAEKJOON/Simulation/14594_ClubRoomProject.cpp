#include<iostream>
#include<vector>

using namespace std;

int main(){
    int roomCnt = 0;
    int behaviorCnt = 0;

    cin >> roomCnt >> behaviorCnt;

    vector<int> rooms = vector<int>(roomCnt);

    for(int i = 0; i < behaviorCnt; i++){
        int x = 0, y = 0;
        cin >> x >> y;

        for(int roomNum = x + 1; roomNum <= y; roomNum++){
            rooms.erase(rooms.begin() + roomNum);
            
        }
    }

    cout << rooms.size();
}
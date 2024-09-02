#include<iostream>

using namespace std;

int main(){
    int apartment[210] = {};

    int testCase, targetFloor, targetRoom;
    int sum = 0;

    cin >> testCase;

    while (testCase--)
    {
        cin >> targetFloor >> targetRoom;


        for(int room = 0; room < (targetFloor  + 1) * targetRoom; room++){
            sum = 0;
            if(room < targetRoom){
                apartment[room] = room + 1;
            }
            else{
                for(int temp = targetRoom * ((room - targetRoom) / targetRoom);
                    temp <= room - targetRoom;
                    temp++){
                    sum += apartment[temp];
                }

                apartment[room] = sum;
            }
        }

        cout << apartment[(targetFloor + 1) * targetRoom - 1] << "\n";
    }
}
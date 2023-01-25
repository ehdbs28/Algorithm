#include<iostream>
#include<vector>

using namespace std;

int main(){
    int balloonCount;
    vector<int> balloons;

    cin >> balloonCount;

    for(int i = 0; i < balloonCount; i++)
        balloons.push_back(i + 1);

    for(int i = 0; i < balloonCount; i++){
        int deleteIndex = 0;
        cin >> deleteIndex;

        for(int j = 0; j < deleteIndex; j++){
            
        }
    }
}
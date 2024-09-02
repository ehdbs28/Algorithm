#include<iostream>
#include<queue>

using namespace std;

struct coordinateSort{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }

        return a.second > b.second;
    }
};

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, coordinateSort> numbers;

    int numberCount, x, y;

    cin >> numberCount;

    for(int i = 0; i < numberCount; i++){
        cin >> x >> y;
        numbers.push({ x, y });
    }

    while(!numbers.empty()){
        cout << numbers.top().first << " " << numbers.top().second << "\n";
        numbers.pop();
    }
}
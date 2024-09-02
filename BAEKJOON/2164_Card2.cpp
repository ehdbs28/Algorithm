#include<iostream>
#include<queue>

using namespace std;

int main(){
    int N;
    queue<int> deck;

    cin >> N;
    for(int i = 1; i <= N; i++){
        deck.push(i);
    }

    while(deck.size() != 1){
        deck.pop();
        int temp = deck.front();
        deck.pop();
        deck.push(temp);
    }

    cout << deck.front();
}
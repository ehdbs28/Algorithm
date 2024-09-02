#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

    int top_count;
    stack<pair<int, int>> towers; 

    cin >> top_count;

    for(int i = 0; i < top_count; i++){
        int height;
        int answer = 0;
        cin >> height;

        while(!towers.empty() && towers.top().first < height) towers.pop();
        if(!towers.empty()) answer = towers.top().second + 1;
        towers.push(pair<int, int>(height, i));

        cout << answer << " ";
    }
}
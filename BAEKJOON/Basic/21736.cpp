#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    int m;

    pair<int, int> st;
    int answer = 0;

    char board[601][601] = {};
    bool check[601][601] = {};

    int destX[4] = { -1, 1, 0, 0 };
    int destY[4] = { 0, 0, -1, 1 };

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < m; j++){
            board[i][j] = input[j];
            if(board[i][j] == 'I'){
                st = { j, i };
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(st);
    check[st.second][st.first] = true;

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pair<int, int> next = { node.first + destX[i], node.second + destY[i] };

            if(next.first < 0 || next.first >= m || next.second < 0 || next.second >= n)
                continue;
            if(check[next.second][next.first] == true)
                continue;
            if(board[next.second][next.first] == 'X')
                continue;

            if(board[next.second][next.first] == 'P')
                ++answer;
            
            check[next.second][next.first] = true;
            q.push(next);
        }
    }

    if(answer == 0){
        cout << "TT";
    }
    else{
        cout << answer;
    }
}
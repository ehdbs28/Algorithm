#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int main(){
    int n;
    int m;

    int miro[101][101];
    int check[101][101];
    memset(check, -1, sizeof(check));

    int destX[4] = { -1, 1, 0, 0 };
    int destY[4] = { 0, 0, -1, 1 };

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        string value;
        cin >> value;
        for(int j = 0; j < m; j++){
            miro[i][j + 1] = value[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    check[1][1] = 1;
    q.push({ 1, 1 });

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            pair<int, int> next = { node.first + destX[i], node.second + destY[i] };

            if(node.first < 1 || node.first > 100 || node.second < 1 || node.second > 100)
                continue;
            if(miro[next.second][next.first] != 1)
                continue;
            if(check[next.second][next.first] != -1 && check[next.second][next.first] <= check[node.second][node.first] + 1)
                continue;

            check[next.second][next.first] = check[node.second][node.first] + 1;
            q.push(next);
        }
    }

    cout << check[n][m];
}
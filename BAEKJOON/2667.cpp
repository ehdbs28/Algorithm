#include<iostream>
#include<queue>
#include<string>

using namespace std;

int n;
int arr[26][26] = {};

int destX[4] = { -1, 1, 0, 0 };
int destY[4] = { 0, 0, -1, 1 };

priority_queue<int, vector<int>, greater<int>> answer;

int search(int x, int y){
    queue<pair<int, int>> q;
    int room = 0;

    arr[y][x] = 2;
    q.push({ x, y });

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        ++room;

        for(int i = 0; i < 4; i++){
            int posX = node.first + destX[i];
            int posY = node.second + destY[i];

            if(posX < 0 || posX > n || posY < 0 || posY > n)
                continue;
            if(arr[posY][posX] == 0)
                continue;
            if(arr[posY][posX] > 1)
                continue;

            arr[posY][posX] = 2;
            q.push({ posX, posY });
        }
    }

    return room;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        for(int j = 0; j < n; j++){
            arr[i][j] = line[j] - '0';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0 || arr[i][j] > 1)
                continue;

            answer.push(search(j, i));
        }
    }

    cout << answer.size() << "\n";
    while(answer.empty() == false){
        cout << answer.top() << "\n";
        answer.pop();
    }
}
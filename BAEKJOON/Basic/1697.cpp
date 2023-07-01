#include<iostream>
#include<queue>

using namespace std;

bool check[100001] = {};

int main(){
    int n;
    int k;

    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({ n, 0 });

    while(q.empty() == false){
        pair<int, int> node = q.front();
        q.pop();

        if(node.first == k){
            cout << node.second;
            break;
        }

        if(node.first + 1 <= k && check[node.first + 1] == false && n < k){
            check[node.first + 1] = true;
            q.push({ node.first + 1, node.second + 1 });
        }

        if(node.first - 1 >= 0 && check[node.first - 1] == false){
            check[node.first - 1] = true;
            q.push({ node.first - 1, node.second + 1 });
        }

        if(node.first * 2 <= k + 1 && check[node.first * 2] == false && n < k){
            check[node.first * 2] = true;
            q.push({ node.first * 2, node.second + 1 });
        }
    }
}
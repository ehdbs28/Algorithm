#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int D(int origin);
int S(int origin);
int L(int origin);
int R(int origin);

void check_num(int next, queue<pair<int, string>> &q, bool* check, string cmd){
    if(check[next] == true)
        return;

    check[next] = true;
    q.push({ next, cmd });
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int a;
        int b;

        bool check[10001] = {};

        cin >> a >> b;

        queue<pair<int, string>> q;
        q.push({ a, "" });
        check[a] = true;

        while(!q.empty()){
            pair<int, string> node = q.front();
            q.pop();

            if(node.first == b){
                cout << node.second << "\n";
                break;
            }

            check_num(D(node.first), q, check, node.second + "D");
            check_num(S(node.first), q, check, node.second + "S");
            check_num(L(node.first), q, check, node.second + "L");
            check_num(R(node.first), q, check, node.second + "R");
        }
    }
}

int D(int origin){
    return (origin * 2) % 10000;
}

int S(int origin){
    return (origin - 1 >= 0 ? origin - 1 : 9999);
}

int L(int origin){
    return (origin % 1000) * 10 + (origin / 1000);
}

int R(int origin){
    return origin / 10 + (origin % 10) * 1000;
}
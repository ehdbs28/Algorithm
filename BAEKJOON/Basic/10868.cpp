#include<iostream>
#include<cmath>
#include<vector>
#include<climits>

using namespace std;

vector<long> tree;

int n;
int m;

void SetTree(int i);
long GetMin(int s, int e);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    int N = n;
    int treeHeight = 0;

    while(N != 0){
        N /= 2;
        treeHeight++;
    }

    int treeSize = (int)(pow(2, treeHeight + 1));
    int leftStartIndex = treeSize / 2;
    tree = vector<long>(treeSize + 1, LONG_MAX);

    for(int i = leftStartIndex + 1; i <= leftStartIndex + n; i++){
        cin >> tree[i];
    }
    SetTree(treeSize - 1);

    for(int i = 0; i < m; i++){
        int s, e;

        cin >> s >> e;

        s = s + leftStartIndex;
        e = e + leftStartIndex;

        cout << GetMin(s, e) << "\n";
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] = min(tree[i / 2], tree[i]);
        i--;
    }
}

long GetMin(int s, int e){
    long val = LONG_MAX;

    while(s <= e){
        if(s % 2 == 1){
            val = min(val, tree[s]);
            s++;
        }
        if(e % 2 == 0){
            val = min(val, tree[e]);
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return val;
}

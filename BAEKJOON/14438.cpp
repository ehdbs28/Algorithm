#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

vector<long> tree;

void SetTree(int i);
long GetMin(int s, int e);
void Update(int i, long val);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    int treeHeight = 0;
    int N = n;

    while(N != 0){
        treeHeight++;
        N /= 2;
    }

    int treeSize = (int)(pow(2, treeHeight + 1));
    int leftStartIdx = treeSize / 2 - 1;
    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), LONG_MAX);

    for(int i = leftStartIdx + 1; i <= leftStartIdx + n; i++){
        cin >> tree[i];
    }
    SetTree(treeSize - 1);

    int m;

    cin >> m;

    for(int i = 0; i < m; i++){
        long a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            Update(leftStartIdx + b, c);
        }
        else if(a == 2){
            b = b + leftStartIdx;
            c = c + leftStartIdx;

            cout << GetMin(b, c) << "\n";
        }
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] = min(tree[i / 2], tree[i]);
        i--;
    }
}

long GetMin(int s, int e){
    long v = LONG_MAX;

    while(s <= e){
        if(s % 2 == 1){
            v = min(v, tree[s]);
            s++;
        }

        if(e % 2 == 0){
            v = min(v, tree[e]);
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return v;
}

void Update(int i, long val){
    tree[i] = val;

    while(i > 1){
        i /= 2;
        tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
    }
}
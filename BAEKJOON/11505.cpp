#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

#define MOD 1000000007

vector<long> tree;

void SetTree(int i);
long GetMul(int s, int e);
void Update(int i, long val);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;
    int k;

    cin >> n >> m >> k;

    int treeHeight = 0;
    int N = n;

    while(N != 0){
        N /= 2;
        treeHeight++;
    }

    int treeSize = (int)(pow(2, treeHeight + 1));
    int leftStartIdx = treeSize / 2;
    tree.resize(treeSize + 1);
    fill(tree.begin(), tree.end(), 1);

    for(int i = leftStartIdx + 1; i <= leftStartIdx + n; i++){
        cin >> tree[i];
    }
    SetTree(treeSize - 1);

    for(int i = 0; i < m + k; i++){
        long a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            Update(leftStartIdx + b, c);
        }
        else if(a == 2){
            b = b + leftStartIdx;
            c = c + leftStartIdx;
            cout << GetMul(b, c) << "\n";
        }
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] = tree[i / 2] * tree[i] % MOD;
        i--;
    }
}

long GetMul(int s, int e){
    long val = 1;

    while(s <= e){
        if(s % 2 == 1){
            val = val * tree[s] % MOD;
            s++;
        }
        if(e % 2 == 0){
            val = val * tree[e] % MOD;
            e--;
        }
        s /= 2;
        e /= 2;
    }

    return val;
}

void Update(int i, long val){
    tree[i] = val;

    while(i > 1){
        i /= 2;
        tree[i] = tree[i * 2] % MOD * tree[i * 2 + 1] % MOD;
    }
}
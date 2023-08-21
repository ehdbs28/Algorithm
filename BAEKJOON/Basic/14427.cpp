#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

vector<pair<long, int>> tree;

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
    int leftStartIdx = treeSize / 2;
    tree.resize(treeSize + 1);

    for(int i = 0; i < treeSize + 1; i++){
        tree[i] = {LONG_MAX, 0};
    }

    for(int i = leftStartIdx + 1; i <= leftStartIdx + n; i++){
        cin >> tree[i].first;
        tree[i].second = i - leftStartIdx;
    }
    SetTree(treeSize - 1);

    int m;

    cin >> m;

    for(int i = 0; i < m; i++){
        int a;
        cin >> a;

        if(a == 1){
            long b, c;
            cin >> b >> c;

            Update(leftStartIdx + b, c);
        }
        else if(a == 2){
            cout << GetMin(1, n) << "\n";
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
    int idx;

    while(s <= e){
        if(s % 2 == 1){
            if(v > tree[s].first){
                v = tree[s].first;
                idx = tree[s].second;
            }
            s++;
        }

        if(e % 2 == 0){
            if(v > tree[e].first){
                v = tree[e].first;
                idx = tree[e].second;
            }
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return idx;
}

void Update(int i, long val){
    tree[i].first = val;

    while(i > 1){
        i /= 2;
        if(tree[i * 2] > tree[i * 2 + 1]){
            tree[i] = tree[i * 2 + 1];
        }
        else if(tree[i * 2] < tree[i * 2 + 1]){
            tree[i] = tree[i * 2];
        }
    }
}
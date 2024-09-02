#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

vector<long> minTree;
vector<long> maxTree;

void SetTree(int i);

long GetMin(int s, int e);
long GetMax(int s, int e);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    int treeHeight = 0;
    int N = n;

    while(N != 0){
        N /= 2;
        treeHeight++;
    }

    int treeSize = (int)(pow(2, treeHeight + 1));
    int leftStartIdx = treeSize / 2;
    minTree.resize(treeSize + 1);
    maxTree.resize(treeSize + 1);
    fill(minTree.begin(), minTree.end(), LONG_MAX);

    for(int i = leftStartIdx + 1; i <= leftStartIdx + n; i++){
        cin >> minTree[i];
        maxTree[i] = minTree[i];
    }

    SetTree(treeSize - 1);

    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;

        s = s + leftStartIdx;
        e = e + leftStartIdx;

        cout << GetMin(s, e) << " " << GetMax(s, e) << "\n";
    }
}

void SetTree(int i){
    while(i != 1){
        minTree[i / 2] = min(minTree[i / 2], minTree[i]);
        maxTree[i / 2] = max(maxTree[i / 2], maxTree[i]);
        i--;
    }
}

long GetMin(int s, int e){
    long val = LONG_MAX;

    while(s <= e){
        if(s % 2 == 1){
            val = min(val, minTree[s]);
            s++;
        }

        if(e % 2 == 0){
            val = min(val, minTree[e]);
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return val;
}

long GetMax(int s, int e){
    long val = 0;

    while(s <= e){
        if(s % 2 == 1){
            val = max(val, maxTree[s]);
            s++;
        }

        if(e % 2 == 0){
            val = max(val, maxTree[e]);
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return val;
}
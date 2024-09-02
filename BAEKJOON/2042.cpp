#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<long> tree;

int n;
int m;
int k;

void SetTree(int i);
long GetSum(int s, int e);
void ChangeVal(int idx, long val);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    int treeHeight = 0;
    int N = n;

    while(N != 0){
        N /= 2;
        ++treeHeight;
    }

    int treeSize = (int)(pow(2, treeHeight + 1));
    int leftNodeStartIdx = treeSize / 2 - 1;
    tree.resize(treeSize + 1);

    for(int i = leftNodeStartIdx + 1; i <= leftNodeStartIdx + n; i++){
        cin >> tree[i];
    }

    SetTree(treeSize - 1);

    for(int i = 0; i < m + k; i++){
        long a, b, c;

        cin >> a >> b >> c;

        if(a == 1){
            ChangeVal(leftNodeStartIdx + b, c);
        }
        else if(a == 2){
            b = b + leftNodeStartIdx;
            c = c + leftNodeStartIdx;
            cout << GetSum(b, c) << "\n";
        }
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] += tree[i];
        --i;
    }
}

long GetSum(int s, int e){
    long sum = 0;

    while(s <= e){
        if(s % 2 == 1){
            sum += tree[s];
            ++s;
        }
        if(e % 2 == 0){
            sum += tree[e];
            --e;
        }
        s /= 2;
        e /= 2;
    }

    return sum;
}

void ChangeVal(int i, long val){
    long diff = val - tree[i];

    while(i > 0){
        tree[i] = tree[i] + diff;
        i /= 2;
    }
}
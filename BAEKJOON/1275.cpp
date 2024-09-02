#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<long> tree;

void SetTree(int i);
long GetSum(int s, int e);
void Update(int i, long v);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    int m;

    cin >> n >> m;

    int height = 0;
    int N = n;

    while(N != 0){
        height++;
        N /= 2;
    }

    int size = (int)(pow(2, height + 1));
    int leftIdx = size / 2;
    tree.resize(size + 1);

    for(int i = leftIdx + 1; i <= leftIdx + n; i++){
        cin >> tree[i];
    }
    SetTree(size - 1);

    for(int i = 0; i < m; i++){
        long x, y, a, b;
        cin >> x >> y >> a >> b;

        if(x > y){
            long temp = x;
            x = y;
            y = temp;
        }

        x = x + leftIdx;
        y = y + leftIdx;

        cout << GetSum(x, y) << "\n";

        Update(a + leftIdx, b);
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] += tree[i];
        i--;
    }
}

long GetSum(int s, int e){
    long v = 0;

    while(s <= e){
        if(s % 2 == 1){
            v += tree[s];
            s++;
        }

        if(e % 2 == 0){
            v += tree[e];
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return v;
}

void Update(int i, long v){
    long diff = v - tree[i];

    while(i > 0){
        tree[i] += diff;
        i /= 2;
    }
}
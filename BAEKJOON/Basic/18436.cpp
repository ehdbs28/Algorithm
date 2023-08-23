#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

vector<long> evenTree;
vector<long> oddTree;

void SetTree(int i);
long GetEven(int s, int e);
long GetOdd(int s, int e);
void Update(int i, long v);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    int height = 0;
    int N = n;

    while(N != 0){
        height++;
        N /= 2;
    }

    int size = int(pow(2, height + 1));
    int leftIdx = size / 2;
    evenTree.resize(size + 1);
    oddTree.resize(size + 1);

    for(int i = leftIdx + 1; i <= leftIdx + n; i++){
        long v;
        cin >> v;

        if(v % 2 == 0){
            evenTree[i]++;
        }
        else{
            oddTree[i]++;
        }
    }

    SetTree(size - 1);

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        long a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            Update(leftIdx + b, c);
        }
        else if(a == 2){
            b += leftIdx;
            c += leftIdx;

            cout << GetEven(b, c) << "\n";
        }
        else if(a == 3){
            b += leftIdx;
            c += leftIdx;

            cout << GetOdd(b, c) << "\n";
        }
    }
}

void SetTree(int i){
    while(i != 1){
        evenTree[i / 2] += evenTree[i];
        oddTree[i / 2] += oddTree[i];
        i--;
    }
}

long GetEven(int s, int e){
    long v = 0;

    while(s <= e){
        if(s % 2 == 1){
            v += evenTree[s];
            s++;
        }

        if(e % 2 == 0){
            v += evenTree[e];
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return v;
}

long GetOdd(int s, int e){
    long v = 0;

    while(s <= e){
        if(s % 2 == 1){
            v += oddTree[s];
            s++;
        }

        if(e % 2 == 0){
            v += oddTree[e];
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return v;
}

void Update(int i, long v){
    if(v % 2 == 0){
        evenTree[i] = 1;
        oddTree[i] = 0;

        while(i > 1){
            i /= 2;
            evenTree[i] = evenTree[i * 2] + evenTree[i * 2 + 1];
            oddTree[i] = oddTree[i * 2] + oddTree[i * 2 + 1];
        }
    }
    else if(v % 2 == 1){
        oddTree[i] = 1;
        evenTree[i] = 0;

        while(i > 1){
            i /= 2;
            oddTree[i] = oddTree[i * 2] + oddTree[i * 2 + 1];
            evenTree[i] = evenTree[i * 2] + evenTree[i * 2 + 1];
        }
    }
}
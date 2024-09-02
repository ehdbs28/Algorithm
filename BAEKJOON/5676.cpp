#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<long> tree;

void SetTree(int i);
long GetMul(int s, int e);
void Update(int i, long v);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;

    while(cin >> n >> m){
        int height = 0;
        int N = n;

        while(N != 0){
            height++;
            N /= 2;
        }

        int size = int(pow(2, height + 1));
        int leftIdx = size / 2 - 1;
        tree.resize(size + 1);
        fill(tree.begin(), tree.end(), 1);

        for(int i = leftIdx + 1; i <= leftIdx + n; i++){
            long v;
            cin >> v;

            if(v > 0){
                tree[i] = 1;
            }
            else if(v < 0){
                tree[i] = -1;
            }
            else{
                tree[i] = 0;
            }
        }

        SetTree(size - 1);

        for(int i = 0; i < m; i++){
            char op;
            long a, b;

            cin >> op >> a >> b;

            if(op == 'C'){
                if(b > 0)
                    b = 1;
                else if(b < 0)
                    b = -1;
                else
                    b = 0;

                Update(leftIdx + a, b);
            }
            else if(op == 'P'){
                a += leftIdx;
                b += leftIdx;

                long v = GetMul(a, b);

                if(v > 0){
                    cout << "+";
                }
                else if(v < 0){
                    cout << "-";
                }
                else{
                    cout << "0";
                }
            }
        }
        cout << "\n";
    }
}

void SetTree(int i){
    while(i != 1){
        tree[i / 2] *= tree[i];
        i--;
    }
}

long GetMul(int s, int e){
    long val = 1;

    while(s <= e){
        if(s % 2 == 1){
            val *= tree[s];
            s++;
        }

        if(e % 2 == 0){
            val *= tree[e--];
            e--;
        }

        s /= 2;
        e /= 2;
    }

    return val;
}

void Update(int i, long v){
    tree[i] = v;

    while(i > 1){
        i /= 2;
        tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }
}

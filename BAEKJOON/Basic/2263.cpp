#include<iostream>

using namespace std;

int n;

int inOrder[100001] = {};
int postOrder[100001] = {};
int idx[100001] = {};

void preOrder(int left, int right, int start, int end){
    if(left > right || start > end)
        return;

    int i = idx[postOrder[end]];
    int leftSize = i - left;
    cout << inOrder[i] << " ";

    preOrder(left, i - 1, start, start + leftSize - 1);
    preOrder(i + 1, right, start + leftSize, end - 1);
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> inOrder[i];
        idx[inOrder[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> postOrder[i];
    }

    preOrder(1, n, 1, n);
}
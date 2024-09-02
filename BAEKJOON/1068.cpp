#include<iostream>
#include<vector>

using namespace std;

int n;
int mainRoot;

int rootCnt = 0;
int removedRoot;

vector<int> v[51];

void GetRootCnt(int m){
    if(m == removedRoot)
        return;

    bool connect = false;

    for(int i = 0; i < v[m].size(); i++){
        if(v[m][i] == removedRoot)
            continue;

        connect = true;
        GetRootCnt(v[m][i]);
    }

    if(!connect){
        rootCnt++;
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int root;
        cin >> root;

        if(root != -1){
            v[root].push_back(i);
        }
        else{
            mainRoot = i;
        }
    }

    cin >> removedRoot;

    GetRootCnt(mainRoot);

    cout << rootCnt;
}
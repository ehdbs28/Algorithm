#include<iostream>
#include<set>

using namespace std;

int main(){
    set<int> s;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        auto iter = s.upper_bound(num);

        if(iter != s.begin()){
            iter--;
            cout << *iter << "\n";
            s.erase(iter);
        }
        else{
            cout << -1 << "\n";
        }
    }
}
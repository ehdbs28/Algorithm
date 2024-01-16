#include <iostream>
#include<set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> s;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s.insert(num);
    }

    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        cout << (s.lower_bound(num) == s.end() ? -1 : *s.lower_bound(num)) << "\n";
    }
}
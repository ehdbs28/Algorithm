#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);

        if(i % 2 == 0){
            sort(v.begin(), v.end());
            cout << v[v.size() / 2] << " ";
        }
    }
}
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

void add(){
    int k, v;
    cin >> k >> v;
    m[k] = v;
}

void remove(){
    int k;
    cin >> k;
    m.erase(k);
}

void find(){
    int k;
    cin >> k;
    cout << (m.find(k) == m.end() ? "None" : to_string(m[k])) << "\n";
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string order;
        cin >> order;

        if(order == "add"){
            add();
        }
        else if(order == "remove"){
            remove();
        }
        else if(order == "find"){
            find();
        }
    }
}
#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

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

void print_list(){
    if(m.empty()){
        cout << "None" << "\n";
    }
    else{
        for(auto& pair : m){
            cout << pair.second << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string method;
        cin >> method;

        if(method == "add"){
            add();
        }
        else if(method == "find"){
            find();
        }
        else if(method == "remove"){
            remove();
        }
        else if(method == "print_list"){
            print_list();
        }
    }
}
#include<iostream>
#include<set>

using namespace std;

set<int> s;

void add(){
    int n;
    cin >> n;
    s.insert(n);
}

void remove(){
    int n;
    cin >> n;
    s.erase(n);
}

void find(){
    int n;
    cin >> n;
    cout << (s.find(n) == s.end() ? "false" : "true") << "\n";
}

void lower_bound(){
    int n;
    cin >> n;
    cout << (s.lower_bound(n) == s.end() ? "None" : to_string(*s.lower_bound(n))) << "\n";
}

void upper_bound(){
    int n;
    cin >> n;
    cout << (s.upper_bound(n) == s.end() ? "None" : to_string(*s.upper_bound(n))) << "\n";
}

void largest(){
    cout << (s.empty() ? "None" : to_string(*s.rbegin())) << "\n";
}

void smallest(){
    cout << (s.empty() ? "None" : to_string(*s.begin())) << "\n";
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
        else if(order == "lower_bound"){
            lower_bound();
        }
        else if(order == "upper_bound"){
            upper_bound();
        }
        else if(order == "largest"){
            largest();
        }
        else if(order == "smallest"){
            smallest();
        }
    }
}
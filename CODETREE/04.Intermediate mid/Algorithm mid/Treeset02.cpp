#include <iostream>
#include <set>

using namespace std;

set<int> s;

void Insert(){
    int x;
    cin >> x;
    s.insert(x);
}

void Delete(){
    int order;
    cin >> order;
    if(!s.empty()){
        if(order == 1){
            s.erase(*s.rbegin());
        }
        else{
            s.erase(*s.begin());
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        s.clear();

        for(int i = 0; i < n; i++){
            string order;
            cin >> order;
            if(order == "I"){
                Insert();
            }
            else if(order == "D"){
                Delete();
            }
        }

        if(s.empty()){
            cout << "EMPTY" << "\n";
        }
        else{
            cout << *s.rbegin() << " " << *s.begin() << "\n";
        }
    }
}
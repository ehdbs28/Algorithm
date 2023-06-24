#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int m;
    int set = 0;

    cin >> m;

    for(int i = 0; i < m; i++){
        string order;
        int n;

        cin >> order;

        if(order == "add"){
            cin >> n;
            set = set | (1 << n);
        }
        else if(order == "remove"){
            cin >> n;
            set = set & ~(1 << n);
        }
        else if(order == "check"){
            cin >> n;
            cout << (set >> n) % 2 << "\n";
        }
        else if(order == "toggle"){
            cin >> n;
            set = set ^ (1 << n);
        }
        else if(order == "all"){
            set = (1 << 21) - 1;
        }
        else if(order == "empty"){
            set = 0;
        }
    }
}
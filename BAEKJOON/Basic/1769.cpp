#include<iostream>
#include<string>

using namespace std;

int main(){
    string x;
    int cnt = 0;
    
    cin >> x;
    
    while(true){
        if(x.size() == 1){
            cout << cnt << "\n";
            cout << (stoi(x) % 3 == 0 ? "YES" : "NO");
            break;
        }
        
        int temp = 0;
        cnt++;
        
        for(int i = 0; i < x.size(); i++){
            temp += x[i] - '0';
        }

        x = to_string(temp);
    }
}

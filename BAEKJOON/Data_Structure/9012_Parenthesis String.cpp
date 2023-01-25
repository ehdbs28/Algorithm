#include<iostream>
#include<string>

using namespace std;

bool IsVPX(string st);

int main(){
    int count;
    cin >> count;

    for(int i = 0; i < count; i++){
        string PS;
        cin >> PS;
        cout << ((IsVPX(PS)) ? "YES" : "NO") << "\n";
    }
}

bool IsVPX(string st){
    if(st[0] == ')' || st[st.length() - 1] == '(') return false;

    int lenght = st.length();
    for(int i = 0; i < lenght; i++){
        if(st[i] == '(' && st[i + 1] == ')'){
            st.erase(st.begin() + i);
            st.erase(st.begin() + i);

            i = -1;
        }
    }

    return (st.empty()) ? true : false;
}
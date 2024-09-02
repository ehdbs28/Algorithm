#include<iostream>
#include<string>
#include<climits>

using namespace std;

int stringMinus(const string &a, const string &b){
    int answer = 0;

    for(int i = 0; i < a.length(); i++){
        if(a[i] != ' ' && a[i] != b[i])
            ++answer;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string a;
    string b;

    cin >> a >> b;

    int answer = INT_MAX;

    while(a.length() <= b.length()){
        answer = min(answer, stringMinus(a, b));
        a = " " + a;
    }

    cout << answer;
}
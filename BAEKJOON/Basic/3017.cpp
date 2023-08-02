#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string a;
string b;

int n;
bool complete = false;

char* check;
bool visited[60] = {};

void search1(int cnt){
    if(check < a)
        return;

    if(cnt == n){
        complete = true;
        return;
    }

    char temp = ' ';

    for(int i = 0; i < n; i++){
        if(b[i] != temp && !visited[i]){
            check[cnt] = b[i];
            temp = b[i];
            visited[i] = true;
            search1(cnt + 1);

            if(complete)
                break;

            visited[i] = false;
        }
    }
}

void search2(int cnt){
    if(check >= a)
        return;

    if(cnt == n){
        complete = true;
        return;
    }

    char temp = ' ';

    for(int i = 0; i < n; i++){
        if(!(cnt == 0 && b[i] == '0') && b[i] != temp && !visited[i]){
            check[cnt] = b[i];
            temp = b[i];
            visited[i] = true;
            search2(cnt + 1);

            if(complete)
                break;

            visited[i] = false;
        }
    }
}

int main(){
    cin >> a >> b;

    if(a == b){
        cout << b << "\n" << 0;
        return 0;
    }

    n = b.length();
    sort(b.begin(), b.end(), less<>());

    check = new char[n];
    fill(check, check + n, '9');
    search1(0);
    cout << (complete ? check : "0") << "\n";

    complete = false;
    sort(b.begin(), b.end(), greater<>());
    fill(check, check + n, '0');
    fill(visited, visited + n, false);
    search2(0);
    cout << (complete ? check : "0");
}
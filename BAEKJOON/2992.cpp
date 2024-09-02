#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int n;
int m;

int answer = INT_MAX;

int arr[6] = {};
int check[6] = {};
bool visited[6] = {};

void func(int cnt){
    if(cnt == m){
        int temp = 0;
        for(int i = 0; i < m; i++){
            temp += arr[check[i]] * pow(10, m - i - 1);
        }

        if(temp > n)
            answer = min(answer, temp);

        return;
    }

    for(int i = 0; i < m; i++){
        if(!visited[i]){
            check[cnt] = i;
            visited[i] = true;
            func(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n;

    string temp = to_string(n);
    m = temp.length();

    for(int i = 0; i < m; i++){
        arr[i] = temp[i] - '0';
    }

    func(0);

    if(answer == INT_MAX)
        cout << 0;
    else
        cout << answer;
}
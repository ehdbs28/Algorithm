#include<iostream>
#include<string>

using namespace std;

int main(){
    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int a, b;
        cin >> a >> b;
        printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b);
    }
}
#include<iostream>
#include<string>

using namespace std;

int main(){
    int cnt = 0;
    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        int a, b;
        cin >> a >> b;
        printf("Case #%d: %d\n", i + 1, a + b);
    }
}
#include<iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int a, b;
    cin >> a >> b;

    int temp = a;
    for(int i = 1; i < b; i++){
      temp = temp * a % 10;
    }

    if(temp % 10 == 0)
      cout << 10 << "\n";
    else
      cout << temp % 10 << "\n";
  }
}

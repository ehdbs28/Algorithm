#include<iostream>
#include<cmath>

using namespace std;

void Hanoi(int num, int from, int by, int to);

int main(){
    int n;

    cin >> n;

    cout << (int)pow(2, n) - 1 << "\n";
    Hanoi(n, 1, 2, 3);
}

void Hanoi(int num, int from, int by, int to){
    if(num == 0)
        return;
    
    Hanoi(num - 1, from, to, by);
    cout << from << " " << to << "\n";
    Hanoi(num - 1, by, from, to);
}
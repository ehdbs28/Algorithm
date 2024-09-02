#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL);

    int arraySize, n;

    cin >> arraySize >> n;

    while (arraySize--)
    {
        int num;
        cin >> num;

        if(num >= n) continue;

        cout << num << " ";
    }
}
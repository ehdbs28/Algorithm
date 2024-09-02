#include<iostream>

using namespace std;

int main(){
    int nums[10] = {};
    int a, b, c, num = 0, divide = 10, index;

    cin >> a >> b >> c;
    num = a * b * c;

    while(num > 0){
        index = num % divide;
        ++nums[index];
        num /= divide;
    }

    for(int n : nums){
        cout << n << "\n";
    }
}
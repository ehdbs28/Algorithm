#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long min, max, powNum, j;
    long long array[1000001] = {};

    int count = 0;

    cin >> min >> max;

    for(long long i = 2; i <= sqrt(max); i++){
        powNum = i * i;
        j = (min + powNum - 1) / powNum * powNum;

        for( ; j <= max; j += powNum){
            array[j - min] = 1;
        }
    }

    for(long long i = min; i <= max; i++){
        if(array[i - min] == 0){
            ++count;
        }
    }

    cout << count;
}
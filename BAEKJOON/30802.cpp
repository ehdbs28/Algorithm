#include <iostream>

using namespace std;

int main()
{
    int n;
    int tShirtsSize[6] = {};
    int t, p;

    cin >> n;
    for(int i = 0; i < 6; i++)
    {
        cin >> tShirtsSize[i];
    }
    cin >> t >> p;

    int tShirtCnt = 0;
    int penCnt = 0;

    for(int i = 0; i < 6; i++)
    {
        tShirtCnt += tShirtsSize[i] / t;
        if(tShirtsSize[i] % t != 0)
        {
            tShirtCnt++;
        }
    }
    penCnt = n / p;

    cout << tShirtCnt << "\n" << penCnt << " " << n - penCnt * p;
}
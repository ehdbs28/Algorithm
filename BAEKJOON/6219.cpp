#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool primeNumbers[4000001] = {};
    int a, b, d;
    int cnt = 0;

    cin >> a >> b >> d;

    for(int i = 2; i <= 4000000; i++)
    {
        if(primeNumbers[i])
        {
            continue;
        }

        for(int j = 2 * i; j <= 4000000; j += i)
        {
            primeNumbers[j] = true;
        }
    }

    for(int i = a; i <= b; i++)
    {
        if(primeNumbers[i])
        {
            continue;
        }

        if(to_string(i).find(to_string(d)) != string::npos)
        {
            cnt++;
        }
    }

    cout << cnt;
}
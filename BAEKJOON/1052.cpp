#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int n;
    int k;
    int answer = 0;

    cin >> n >> k;

    while(true)
    {
        bitset<64> binary(n + answer);
        if(binary.count() <= k)
        {
            cout << answer;
            return 0;
        }

        answer++;
    }
}
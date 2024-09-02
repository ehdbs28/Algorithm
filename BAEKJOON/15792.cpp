#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a;
    int b;

    int task = 0;

    cin >> a >> b;

    if((float)a / (float)b - a / b > 0)
    {
        cout << a / b << ".";

        int temp = a - b * (a / b);

        while(true)
        {
            task++;

            if(temp * 10 < b)
            {
                cout << 0;
                temp *= 10;
                continue;
            }

            int value = temp * 10 / b;
            temp = temp * 10 - b * value;

            cout << value;

            if(temp == 0 || task >= 1000)
            {
                break;
            }
        }
    }
    else
    {
        cout << a / b;
    }
}
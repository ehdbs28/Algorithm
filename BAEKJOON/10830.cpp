#include <iostream>

using namespace std;

int n;
long long b;
long long a[5][5];
long long temp[5][5];
long long answer[5][5];

void Multiply_Matrix(long long mat1[5][5], long long mat2[5][5])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                temp[i][j] += mat1[i][k] * mat2[k][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat1[i][j] = temp[i][j];
        }
    }
}

int main()
{
    cin >> n >> b;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        answer[i][i] = 1;
    }

    while(b)
    {
        if(b % 2 == 1)
        {
            Multiply_Matrix(answer, a);
        }

        Multiply_Matrix(a, a);
        b = b >> 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
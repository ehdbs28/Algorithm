#include <iostream>

using namespace std;

int n;
int board[33][33];
long long dp[3][33][33];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }

    dp[0][1][2] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 3; j <= n; j++)
        {
            if(board[i][j] == 0)
            {
                dp[0][i][j] = dp[0][i][j-1] + dp[1][i][j-1];
                dp[2][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
                if(board[i-1][j] == 0 && board[i][j-1] == 0)
                {
                    dp[1][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
                }
            }
        }
    }

    cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n];
}
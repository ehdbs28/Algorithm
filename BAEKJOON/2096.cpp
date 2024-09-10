#include <iostream>

using namespace std;

int n;

int board[100001][3] = {};
int minDP[2][3] = {};
int maxDP[2][3] = {};

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }

    minDP[0][0] = board[0][0];
    minDP[0][1] = board[0][1];
    minDP[0][2] = board[0][2];

    maxDP[0][0] = board[0][0];
    maxDP[0][1] = board[0][1];
    maxDP[0][2] = board[0][2];

    for(int i = 1; i < n; i++)
    {
        // board[0]
        int minVal = min(minDP[0][0] + board[i][0], minDP[0][1] + board[i][0]);
        int maxVal = max(maxDP[0][0] + board[i][0], maxDP[0][1] + board[i][0]);
        minDP[1][0] = minVal;
        maxDP[1][0] = maxVal;

        //board[1]
        minVal = min(min(minDP[0][0] + board[i][1], minDP[0][1] + board[i][1]), minDP[0][2] + board[i][1]);
        maxVal = max(max(maxDP[0][0] + board[i][1], maxDP[0][1] + board[i][1]), maxDP[0][2] + board[i][1]);
        minDP[1][1] = minVal;
        maxDP[1][1] = maxVal;

        //board[2]
        minVal = min(minDP[0][1] + board[i][2], minDP[0][2] + board[i][2]);
        maxVal = max(maxDP[0][1] + board[i][2], maxDP[0][2] + board[i][2]);
        minDP[1][2] = minVal;
        maxDP[1][2] = maxVal;

        // sliding
        minDP[0][0] = minDP[1][0];
        minDP[0][1] = minDP[1][1];
        minDP[0][2] = minDP[1][2];

        maxDP[0][0] = maxDP[1][0];
        maxDP[0][1] = maxDP[1][1];
        maxDP[0][2] = maxDP[1][2];
    }

    cout << max(maxDP[0][2], max(maxDP[0][0],maxDP[0][1])) << " ";
    cout << min(minDP[0][2], min(minDP[0][0],minDP[0][1]));
}
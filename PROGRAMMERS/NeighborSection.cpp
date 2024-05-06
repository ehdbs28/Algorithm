#include <string>
#include <vector>

using namespace std;

int destX[4] = { 0, 0, 1, -1 };
int destY[4] = { 1, -1, 0, 0 };

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;

    string color = board[h][w];

    for(int i = 0; i < 4; i++)
    {
        int nw = w + destX[i];
        int nh = h + destY[i];

        if(nw < 0 || nw >= board[0].size() || nh < 0 || nh >= board.size())
            continue;

        if(board[nh][nw] == color)
        {
            answer++;
        }
    }

    return answer;
}
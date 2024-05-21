#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int n;
    int k;
    int answer = -1;

    cin >> n >> k;

    queue<pair<int, int>> q;
    int check[11] = {};
    q.emplace(n, 0);
    check[0] = n;

    while(!q.empty())
    {
        int curNum = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if(curCnt == k)
        {
            answer = max(answer, curNum);
            continue;
        }

        string str = to_string(curNum);
        for(int i = 0; i < str.size(); i++)
        {
            for(int j = i + 1; j < str.size(); j++)
            {
                if(i == 0 && str[j] == '0')
                    continue;

                string temp = str;
                swap(temp[i], temp[j]);
                int nextNum = stoi(temp);

                if(check[curCnt + 1] >= nextNum)
                    continue;

                check[curCnt + 1] = nextNum;
                q.emplace(nextNum, curCnt + 1);
            }
        }
    }

    cout << answer;
}
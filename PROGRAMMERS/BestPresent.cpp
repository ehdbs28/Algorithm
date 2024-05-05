#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    int giftList[50][50] = {};
    int giftIndex[50] = {};
    int giftCount[50] = {};

    for(int i = 0; i < gifts.size(); i++)
    {
        stringstream ss(gifts[i]);
        string to, from;
        ss >> to >> from;

        int toIndex = friends.size() - (friends.end() - std::find(friends.begin(), friends.end(), to));
        int fromIndex = friends.size() - (friends.end() - std::find(friends.begin(), friends.end(), from));

        giftList[toIndex][fromIndex]++;
    }

    for(int i = 0; i < friends.size(); i++)
    {
        int take = 0;
        int give = 0;

        for(int j = 0; j < friends.size(); j++)
        {
            take += giftList[i][j];
            give += giftList[j][i];
        }

        giftIndex[i] = take - give;
    }

    for(int i = 0; i < friends.size(); i++)
    {
        for(int j = 0; j < friends.size(); j++)
        {
            if(giftList[i][j] > giftList[j][i])
            {
                giftCount[i]++;
            }
            else if(giftList[i][j] == giftList[j][i])
            {
                if(giftIndex[i] > giftIndex[j])
                {
                    giftCount[i]++;
                }
            }
        }
    }

    for(int i = 0; i < friends.size(); i++)
    {
        if(answer <= giftCount[i])
        {
            answer = giftCount[i];
        }
    }

    return answer;
}

int main(){
    cout << solution({"muzi", "ryan", "frodo", "neo"}, {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"});
}
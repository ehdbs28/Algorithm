#include<iostream>
#include<string>
#include<queue>

using namespace std;

int timeToNum(string time){
    int minNum = (time[0] - '0') * 10 + time[1] - '0';
    int secNum = (time[3] - '0') * 10 + time[4] - '0';
    return secNum + minNum * 60;
}

string numToTime(int num){
    int minNum = num / 60;
    int secNum = num % 60;
    return (minNum < 10 ? "0" + to_string(minNum) : to_string(minNum)) + ":" + (secNum < 10 ? "0" + to_string(secNum) : to_string(secNum));
}

int main(){
    int n;

    queue<pair<int, int>> q;

    int aTeamScore = 0;
    int bTeamScore = 0;

    int aTeamTime = 0;
    int bTeamTime = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        int team;
        string time;
        cin >> team >> time;
        q.emplace(team, timeToNum(time));
    }

    for(int i = 0; i < timeToNum("48:00"); i++){
        if(q.front().second == i){
            if(q.front().first == 1){
                aTeamScore++;
            }
            else{
                bTeamScore++;
            }
            q.pop();
        }

        if(aTeamScore > bTeamScore){
            aTeamTime++;
        }
        else if(aTeamScore < bTeamScore){
            bTeamTime++;
        }
    }

    cout << numToTime(aTeamTime) << "\n" << numToTime(bTeamTime);
}
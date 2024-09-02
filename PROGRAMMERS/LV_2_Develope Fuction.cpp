#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int lastDay = 0;

    for(int i = 0; i < progresses.size(); i++){
        int day = ((100 - progresses[i]) % speeds[i] == 0 ?
                (100 - progresses[i]) / speeds[i] : 
                (100 - progresses[i]) / speeds[i] + 1);

        if(!answer.empty() && lastDay >= day){
            answer[answer.size() - 1]++;
        }
        else{
            lastDay = day;
            answer.push_back(1);
        }
    }

    return answer;
}

int main(){

}
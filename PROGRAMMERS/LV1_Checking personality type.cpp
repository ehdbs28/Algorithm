#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string solution(vector<string> surveys, vector<int> choices);

int main(){
    // 1 -> -3
    // 2 -> -2
    // 3 -> -1
    // 4 -> 0
    // 5 -> 1
    // 6 -> 2
    // 7 -> 3

    vector<string> testStringVec = {"AN", "CF", "MJ", "RT", "NA"};
    vector<int> testIntVec = {5, 3, 2, 7, 5};

    cout << solution(testStringVec, testIntVec);
}

string solution(vector<string> surveys, vector<int> choices){
    string personalityType = "";
    int types[4] = {0, 0, 0, 0}; 

    string typenames[4] = {
        "RT",
        "CF",
        "JM",
        "AN"
    };

    for(int i = 0; i < surveys.size(); i++){
        string survey = surveys[i];
        int choice = choices[i];
        int value = 0;
        int type = 0;
        
        string sortSurvey = survey;
        sort(sortSurvey.begin(), sortSurvey.end());

        value = choice - 4;

        switch(sortSurvey.front()){
            case 'R':
                type = 0;
                break;
            case 'C':
                type = 1;
                break;
            case 'J':
                type = 2;
                break;
            case 'A':
                type = 3;
                break;
        }

        if(sortSurvey.front() != survey.front()) value *= -1;
        types[type] += value;
    }

    for(int order = 0; order < sizeof(typenames)/sizeof(*typenames); order++){
        char type = (types[order] > 0) ? typenames[order].back() : typenames[order].front();
        personalityType.push_back(type);
    }

    return personalityType;
}
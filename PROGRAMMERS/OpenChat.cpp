#include<iostream>
#include<vector>
#include<cstring>
#include<map>

using namespace std;

vector<string> split(string s, string divid){
    vector<string> v;
    char* c = strtok((char*)s.c_str(), divid.c_str());
    while(c){
        v.push_back(c);
        c = strtok(NULL, divid.c_str());
    }
    return v;
}

vector<string> solution(vector<string> record){
    map<string, string> users;
    vector<pair<string, string>> records;
    vector<string> v;

    for(auto r : record){
        vector<string> data = split(r, " ");

        if(data[0] != "Change")
            records.push_back({ data[0], data[1] });

        if(data[0] != "Leave")
            users[data[1]] = data[2];
    }

    for(auto pair : records){
        string buf;
        if(pair.first == "Enter"){
            buf = users[pair.second] + "님이 들어왔습니다.";
        }
        else{
            buf = users[pair.second] + "님이 나갔습니다.";
        }
        v.push_back(buf);
    }

    return v;
}

int main(){
    vector<string> input = {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };

    vector<string> answer = solution(input);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << "\n";
    }
}

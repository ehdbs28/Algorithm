#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ans;
bool visited[10001] = {};

int cnt = 0;
bool connect = false;

void DFS(string key, vector<vector<string>> tickets){
    if(cnt == tickets.size())
        connect = true;

    ans.push_back(key);

    for(int i = 0; i < tickets.size(); i++){
        if(!visited[i] && tickets[i][0] == key){
            visited[i] = true;
            cnt++;
            DFS(tickets[i][1], tickets);

            if(!connect){
                ans.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets);
    return ans;
}

int main(){
    solution(vector<vector<string>>{ {"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"} });
}
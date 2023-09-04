#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

bool check(string& target, string& str){
    int cnt = 0;
    for(int i = 0; i < target.size(); i++){
        if(target[i] != str[i])
            cnt++;
    }
    return cnt == 1;
}

int solution(string begin, string target, vector<string> words) {
    int targetIdx = -1;

    for(int i = 0; i < words.size(); i++){
        if(words[i] == target)
            targetIdx = i;
    }

    if(targetIdx == -1)
        return 0;

    vector<int> graph[51] = {};
    int visited[51] = {};

    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.size(); j++){
            if(check(words[i], words[j])){
                graph[i].push_back(j);
            }
        }
    }

    queue<int> q;

    for(int i = 0; i < words.size(); i++){
        if(check(begin, words[i])){
            q.push(i);
            visited[i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];

            if(visited[next] == 0){
                visited[next] = visited[cur] + 1;
                q.push(next);
            }
        }
    }

    return visited[targetIdx];
}

int main(){
    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" });
}
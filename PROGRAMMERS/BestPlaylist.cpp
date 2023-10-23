#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct song{
    int play;
    int idx;

    bool operator()(song a, song b){
        if(a.play == b.play){
            return a.idx > b.idx;
        }

        return a.play < b.play;
    }
};

struct playlist{
    int playCnt;
    priority_queue<song, vector<song>, song> songs;

    bool operator()(playlist a, playlist b){
        return a.playCnt > b.playCnt;
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, playlist> m;
    vector<int> answer;

    for(int i = 0; i < genres.size(); i++){
        m[genres[i]].playCnt += plays[i];
        m[genres[i]].songs.push(song{plays[i], i});
    }

    vector<pair<string, playlist>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](pair<string, playlist> a, pair<string, playlist> b){
        return a.second(a.second, b.second);
    });
    for(auto& item : v){
        for(int i = 0; !item.second.songs.empty() && i < 2; i++){
            answer.push_back(item.second.songs.top().idx);
            item.second.songs.pop();
        }
    }

    return answer;
}

int main(){
    vector<int> v = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }
}
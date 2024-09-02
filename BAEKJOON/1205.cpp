#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    vector<int> scores;

    int n;
    int score;
    int p;

    int rank = 1;
    int cnt = 0;

    cin >> n >> score >> p;

    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        scores.push_back(s);
    }

    sort(scores.begin(), scores.end(), greater<int>());

    for(int i = 0; i < n; i++){
        if(score < scores[i])
            ++rank;
        else if(score == scores[i])
            rank = rank;
        else break;

        ++cnt;
    }

    if(cnt == p) rank = -1;
    if(n == 0) rank = 1;
    
    cout << rank;
}
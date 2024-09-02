#include<iostream>
#include<vector>

using namespace std;

vector<string> split(string &s, char target){
    vector<string> v;

    for(int i = 0; i < s.length(); i++){
        if(v.empty() || s[i] == target)
            v.push_back("");

        if(s[i] == target)
            continue;

        v[v.size() - 1].push_back(s[i]);
    }

    return v;
}

int sum(const vector<string> &v){
    int val = 0;

    for(int i = 0; i < v.size(); i++){
        val += stoi(v[i]);
    }

    return val;
}

int main()
{
    vector<string> splitString;
    string s;

    int answer = 0;

    cin >> s;

    splitString = split(s, '-');

    int temp = sum(split(splitString[0], '+'));
    if(s[0] == '-'){
        answer -= temp;
    }
    else{
        answer += temp;
    }

    for(int i = 1; i < splitString.size(); i++){
        answer -= sum(split(splitString[i], '+'));
    }

    cout << answer;
}
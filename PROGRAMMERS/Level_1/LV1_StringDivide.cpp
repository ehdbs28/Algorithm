#include<iostream>
#include<string>

using namespace std;

int solution(string s);

// int main(){
//     cout << solution("banana");
//     cout << solution("abracadabra");
//     cout << solution("abracadabra");
// }

int solution(string s){
    int answer = 0;
    int index = 0;

    while(index < s.length()){
        char first = s.at(index);
        int sameNum = 0, otherNum = 0;
        for(int i = index; i < s.length(); i++){
            if(s[i] == first) sameNum++;
            else otherNum++;

            if(sameNum == otherNum || i == s.length() - 1){
                answer++;
                index = i + 1;
                break;
            }
        }
    }

    return answer;
}
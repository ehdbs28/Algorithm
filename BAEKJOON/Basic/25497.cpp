#include<iostream>

using namespace std;

int main(){
    int cnt;
    int answer = 0;

    int s = 0;
    int l = 0;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        char skill;
        cin >> skill;

        if(skill == 'S')
            ++s;
        else if(skill == 'L')
            ++l;
        else if(skill == 'R'){
            if(l > 0){
                --l;
                ++answer;
            }
        }
        else if(skill == 'K'){
            if(s > 0){
                --s;
                ++answer;
            }
            else break;
        }
        else{
            ++answer;
        }
    }

    cout << answer;
}
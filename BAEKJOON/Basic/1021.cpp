#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    deque<int> dq;

    int length;

    int cnt;
    int target;

    int answer = 0;

    cin >> length >> cnt;

    for(int i = 1; i <= length; i++){
        dq.push_back(i);
    }

    for(int i = 0; i < cnt; i++){
        cin >> target;

        int isFront = find(dq.begin(), dq.end(), target) <= dq.begin() + dq.size() / 2;

        while(true){
            if(dq.front() == target){
                dq.pop_front();
                break;
            }
            else if(isFront){
                ++answer;
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else{
                ++answer;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << answer;
}
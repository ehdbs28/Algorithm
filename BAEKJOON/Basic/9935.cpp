#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main(){
    deque<char> dq;

    string input;
    string target;

    cin >> input >> target;

    for(int i = 0; i < input.length(); i++){
        dq.push_back(input[i]);
        
        if(target.back() == input[i]){
            string temp = "";

            for(int j = target.length(); j > 0; j--){
                if(dq.empty() == false){
                    temp.push_back(dq.back());
                    dq.pop_back();
                }
            }

            reverse(temp.begin(), temp.end());

            if(temp != target){
                for(int j = 0; j < temp.length(); j++){
                    dq.push_back(temp[j]);
                }
            }
        }
    }

    if(dq.empty()){
        cout << "FRULA";
        return 0;
    }

    while(dq.empty() == false){
        cout << dq.front();
        dq.pop_front();
    }
}
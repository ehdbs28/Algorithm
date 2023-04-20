#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    deque<int> nums;

    int testCase;
    int length;

    int temp;

    int reverse = 0;
    
    string order;
    string input;

    cin >> testCase;

    while(testCase--){
        cin >> order >> length >> input;

        nums.clear();
        reverse = 0;

        for(char ch : input){
            if(ch >= '0' && ch <= '9')
                temp = temp * 10 + (ch - '0');

            if(temp > 0 && (ch == ',' || ch == ']')){
                nums.push_back(temp);
                temp = 0;
            }
        }

        for(int i = 0; i < order.length(); i++){
            if(order[i] == 'R'){
                ++reverse;
            }
            else{
                --length;

                if(nums.empty())
                    break;
                
                if(reverse % 2 == 0){
                    nums.pop_front();
                }
                else{
                    nums.pop_back();
                }
            }
        }

        if(length < 0){
            cout << "error" << "\n";
            continue;
        }

        cout << "[";
        while(!nums.empty()){
            if(reverse % 2 == 0){
                cout << nums.front();
                nums.pop_front();
            }
            else{
                cout << nums.back();
                nums.pop_back();
            }

            if(nums.size() != 0)
                cout << ",";
        }
        cout << "]" << "\n";
    }
}
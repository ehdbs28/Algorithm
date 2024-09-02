#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    vector<int> blocks;
    int blockValues[257] = {};
    pair<int, int> answer{ INT_MAX, -1 };

    int xCount, yCount, initBlock, input;
    int time = 0, height = 0, inventory = 0;

    cin >> yCount >> xCount >> initBlock;

    for(int i = 0; i < yCount * xCount; i++){
        cin >> input;
        
        if(find(blocks.begin(), blocks.end(), input) != blocks.end()){
            ++blockValues[input];
        }
        else{
            blocks.push_back(input);
            ++blockValues[input];
        }
    }

    sort(blocks.begin(), blocks.end(), greater<int>());

    for(int i = 0; i < 257; i++){
        height = i;
        time = 0;
        inventory = initBlock;

        for(int j : blocks){
            if(j == height) continue;

            if(j > height){
                time += (j - height) * blockValues[j] * 2;
                inventory += (j - height) * blockValues[j];
            }
            else{
                if(inventory - ((height - j) * blockValues[j]) >= 0){
                    time += (height - j) * blockValues[j];
                    inventory -= (height - j) * blockValues[j];
                }
                else{
                    time = -1;
                    break;
                }
            }
        }

        if(time != -1){
            if(answer.first == time){
                if(answer.second < height){
                    answer.first = time;
                    answer.second = height;
                }
            }
            else if(answer.first > time){
                answer.first = time;
                answer.second = height;
            }
        }
    }

    if(answer.first == INT_MAX) answer.first = 0;
    std::cout << answer.first << " " << answer.second;
}
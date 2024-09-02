#include<iostream>
#include<vector>
#include<string>

using namespace std;

int solution(vector<int> ingredient);

int main(){
    // Test Code
    vector<int> orderList = {2, 1, 1, 2, 3, 1, 2, 3, 1};

    cout << solution(orderList);
}

int solution(vector<int> ingredient){
    int answer = 0;
    string recipe = "";

    for(int element : ingredient){
        recipe.push_back(element);

        if(recipe.size() < 4) continue;

        if(recipe[recipe.size() - 4] == 1 && recipe[recipe.size() - 3] == 2 && recipe[recipe.size() - 2] == 3 && recipe[recipe.size() - 1] == 1){
            recipe = recipe.substr(0, recipe.size() - 4);
            answer++;
        }
    }        

    return answer;
}

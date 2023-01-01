#include<iostream>
#include<vector>

using namespace std;

enum Element{
    bread = 1,
    vegetable = 2,
    pattie = 3
};
vector<Element> Recipe = {bread, vegetable, pattie, bread};

int solution(vector<int> ingredient);

int main(){
    vector<int> orderList = {1, 2, 3, 1};

    cout << solution(orderList);
}

int solution(vector<int> ingredient){
    int answer = 0;
    vector<Element> recipe = Recipe;

    int* first = &ingredient[0];
    for(size_t i = 0; i < ingredient.size(); ++i){
        if(*(first + i) != recipe[0]) recipe = Recipe;

        if(*(first + i) == recipe[0]) 
            recipe.erase(recipe.begin());

        if(recipe.size() == 0){
            ingredient.erase(ingredient.begin() + (i - 3), ingredient.begin() + i + 1);
            answer++;
            recipe = Recipe;
            break;
        }
    }        

    return (answer == 0) ? 0 : answer + solution(ingredient);
}
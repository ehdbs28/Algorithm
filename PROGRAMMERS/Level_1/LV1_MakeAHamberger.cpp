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
    vector<int> orderList = {2, 1, 1, 2, 3, 1, 2, 3, 1};

    cout << solution(orderList);
}

int solution(vector<int> ingredient){
    int answer = 0;
    vector<Element> recipe = Recipe;

    for(int element = 0; element < ingredient.size(); element++){
        if(ingredient[element] == recipe[0])
            recipe.erase(recipe.begin());
        else
            recipe = Recipe;

        if(recipe.size() == 0){
            ingredient.erase(ingredient.begin() + (element - 3), ingredient.begin() + element);
            answer++;
            recipe = Recipe;
        }
    }        

    return (answer == 0) ? 0 : answer + solution(ingredient);
}
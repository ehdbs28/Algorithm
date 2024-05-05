#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int currentHealth = health;
    int bandageSuccess = 0;

    int attackNum = 0;

    for(int i = 1; i <= attacks[attacks.size() - 1][0]; i++)
    {
        if(attacks[attackNum][0] == i)
        {
            currentHealth -= attacks[attackNum][1];
            bandageSuccess = 0;
            attackNum++;

            if(currentHealth <= 0)
            {
                break;
            }
        }
        else
        {
            bandageSuccess++;
            if(bandageSuccess == bandage[0])
            {
                currentHealth += bandage[1] + bandage[2];
                bandageSuccess = 0;
            }
            else{
                currentHealth += bandage[1];
            }

            if(currentHealth > health)
            {
                currentHealth = health;
            }
        }
    }

    return currentHealth <= 0 ? -1 : currentHealth;
}

int main()
{
    cout << solution({3, 2, 7}, 20, { {1, 15}, {5, 16}, {8,6} });
}
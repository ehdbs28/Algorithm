#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int subjectCount, input, maxScore = 0;
    double sum = 0;
    vector<double> subjectScores;

    cin >> subjectCount;

    for(int i = 0; i < subjectCount; i++){
        cin >> input;
        maxScore = max(maxScore, input);
        subjectScores.push_back(input);
    }

    for(int i = 0; i < subjectCount; i++)
        sum += (double)subjectScores[i]/maxScore * 100;

    cout << sum / (double)subjectCount;
}
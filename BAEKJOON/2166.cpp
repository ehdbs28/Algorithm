#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    vector<pair<double, double>> vertices;
    double vertexCnt;
    double x_input, y_input;
    double area = 0;

    pair<double, double> first, second, third;

    cin >> vertexCnt;

    for(int i = 0; i < vertexCnt; i++){
        cin >> x_input >> y_input;
        vertices.push_back({ x_input, y_input });
    }

    for(int i = 2; i < vertexCnt; i++){
        first = vertices[0];
        second = vertices[i - 1];
        third = vertices[i];

        area += (first.first * second.second + second.first * third.second + third.first * first.second)
                - (second.first * first.second + third.first * second.second + first.first * third.second);
    }

    cout<<fixed;
    cout.precision(1);
    cout << abs(area) / 2;
}
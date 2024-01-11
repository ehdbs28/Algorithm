#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person{
    int height;
    int weight;
    int num;

    bool operator()(const person& a, const person& b){
        if(a.height == b.height){
            return a.weight > b.weight;
        }
        return a.height < b.height;
    }
};

int main() {
    int n;
    cin >> n;

    vector<person> p;

    for(int i = 0; i < n; i++){
        int h, w;
        cin >> h >> w;
        p.push_back(person{h, w, i + 1});
    }

    sort(p.begin(), p.end(), person());
    for(int i = 0; i < n; i++){
        cout << p[i].height << " " << p[i].weight << " " << p[i].num << "\n";
    }
}
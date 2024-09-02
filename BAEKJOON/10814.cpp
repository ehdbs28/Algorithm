#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<pair<int, string>> array;
    int count;
    int age;
    string name;

    cin >> count;

    for(int i = 0; i < count; i++){
        cin >> age >> name;
        array.push_back({ age, name });
    }
    
    stable_sort(array.begin(), array.end(), [](pair<int, string> a, pair<int, string> b){ return a.first < b.first; });

    for(int i = 0; i < count; i++){
        cout << array[i].first << " " << array[i].second << "\n";
    }
}
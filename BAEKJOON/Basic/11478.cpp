#include<iostream>
#include<unordered_set>

using namespace std;

int main()
{
    unordered_set<string> set;
    string s;

    cin >> s;

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            string substr = s.substr(j, i);
            set.insert(substr);
        }
    }

    cout << set.size();
}
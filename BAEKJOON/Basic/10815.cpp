#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<int, bool> map;
    int n, m;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        map.insert({num, true});
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << (map[num] ? 1 : 0) << " ";
    }
}
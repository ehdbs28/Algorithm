#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    vector<int> a;
    vector<int> b;

    cin >> n;
    a.resize(n);
    b.resize(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += a[i] * b[i];
    }
    cout << s;
}
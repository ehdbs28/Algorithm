#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    string p;

    cin >> s >> p;

    if(strstr(s.c_str(), p.c_str()) == nullptr)
    {
        cout << 0;
    }
    else{
        cout << 1;
    }
}
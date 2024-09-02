#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true)
    {
        long long x;
        int n;
        vector<long long> blocks;

        cin >> x >> n;

        if(cin.eof())
        {
            break;
        }

        x = x * 10000000;
        blocks.resize(n);

        for(int i = 0; i < n; i++)
        {
            cin >> blocks[i];
        }
        sort(blocks.begin(), blocks.end());

        int left = 0;
        int right = n - 1;
        bool find = false;

        while(left < right)
        {
            long long lv = blocks[left];
            long long rv = blocks[right];

            if(lv + rv == x)
            {
                cout << "yes " << lv << " " << rv << "\n";
                find = true;
                break;
            }
            else if(lv + rv < x)
            {
                ++left;
            }
            else if(lv + rv > x)
            {
                --right;
            }
        }

        if(!find)
        {
            cout << "danger\n";
        }
    }
}
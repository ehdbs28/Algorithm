#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[101] = {};

int m;
int b[101] = {};

vector<int> answer;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
}

void solve()
{
    for(int i = 0; i < n; i++)
    {
        vector<int> t1;
        const int* v = find(begin(b), begin(b) + m, a[i]);

        if(v != begin(b) + m)
        {
            long si = v - begin(b);
            long it = i;
            int* max_iter = nullptr;
            t1.push_back(*v);

            while(true)
            {
                max_iter = nullptr;

                for(long j = si + 1; j < m; j++)
                {
                    int* t = find(begin(a) + it + 1, begin(a) + n, b[j]);
                    if(t != begin(a) + n && t - begin(a) > it && (max_iter == nullptr || *max_iter < *t))
                    {
                        max_iter = t;
                        si = j;
                    }
                }

                if(max_iter == nullptr)
                {
                    break;
                }

                t1.push_back(*max_iter);
                it = max_iter - begin(a);
            }
        }

        if(answer < t1)
        {
            answer = t1;
        }
    }
}

void output()
{
    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}

int main()
{
    input();
    solve();
    output();
}
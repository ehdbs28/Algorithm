#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        int m, n;
        int x, y;

        cin >> m >> n >> x >> y;

        int result = -1;
        int max = lcm(m, n);

        for(int i = x; i <= max; i += m){
            int tempY = i % n;
            if(tempY == 0){
                tempY = n;
            }

            if(tempY == y){
                result = i;
                break;
            }
        }

        cout << result << "\n";
    }
}
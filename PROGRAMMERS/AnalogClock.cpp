#include <iostream>
#include <vector>

using namespace std;

class Time
{
public:
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    Time(int sec)
    {
        h = sec / 3600;
        m = (sec % 3600) / 60;
        s = (sec % 3600) % 60;
    }

public:
    inline int toSec() { return h * 3600 + m * 60 + s; }

public:
    vector<double> getDegrees()
    {
        double hDegree = (h % 12) * 30 + m * 0.5 + s * (1/120.0);
        double mDegree = m * 6 + s * 0.1;
        double sDegree = s * 6;
        return {hDegree, mDegree, sDegree};
    }

private:
    int h;
    int m;
    int s;

};

bool MatchMinute(vector<double> degrees, vector<double> n_degrees)
{
    if(degrees[1] > degrees[2] && n_degrees[1] <= n_degrees[2])
    {
        return true;
    }

    if(degrees[2] == 354 && degrees[1] > 354)
    {
        return true;
    }

    return false;
}

bool MatchHour(vector<double> degrees, vector<double> n_degrees)
{
    if(degrees[0] > degrees[2] && n_degrees[0] <= n_degrees[2])
    {
        return true;
    }

    if(degrees[2] == 354 && degrees[0] > 354)
    {
        return true;
    }

    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;

    int now = Time(h1, m1, s1).toSec();
    int end = Time(h2, m2, s2).toSec();

    for(int t = now; t < end; t++)
    {
        auto degrees = Time(t).getDegrees();
        auto n_degrees = Time(t + 1).getDegrees();

        bool mMatch = MatchMinute(degrees, n_degrees);
        bool hMatch = MatchHour(degrees, n_degrees);

        if(mMatch && hMatch)
        {
            answer += n_degrees[2] == n_degrees[1] ? 1 : 2;
        }
        else if(mMatch || hMatch)
        {
            answer++;
        }
    }

    if(now == 0 || now == Time(12, 0, 0).toSec())
    {
        answer++;
    }

    return answer;

}

int main()
{
    cout << solution(0, 5, 30, 0, 7, 0) << "\n";
    cout << solution(12, 0, 0, 12, 0, 30) << "\n";
    cout << solution(0, 6, 1, 0, 6, 6) << "\n";
    cout << solution(11, 59, 30, 12, 0, 0) << "\n";
    cout << solution(11, 58, 59, 11, 59, 0) << "\n";
    cout << solution(1, 5, 5, 1, 5, 6) << "\n";
    cout << solution(0, 0, 0, 23, 59, 59);
}
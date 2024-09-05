#include <iostream>

using namespace std;

string GetString(long long num)
{
    if(num % 15 == 0)
    {
        return "FizzBuzz";
    }
    else if(num % 3 == 0)
    {
        return "Fizz";
    }
    else if(num % 5 == 0)
    {
        return "Buzz";
    }
    else
    {
        return to_string(num);
    }
}

int main()
{
    string str[3] = {};
    cin >> str[0] >> str[1] >> str[2];

    if(str[0].find("Fizz") == string::npos && str[0].find("Buzz") == string::npos)
    {
        cout << GetString(stoll(str[0]) + 3);
        return 0;
    }

    if(str[1].find("Fizz") == string::npos && str[1].find("Buzz") == string::npos)
    {
        cout << GetString(stoll(str[1]) + 2);
        return 0;
    }

    if(str[2].find("Fizz") == string::npos && str[2].find("Buzz") == string::npos)
    {
        cout << GetString(stoll(str[2]) + 1);
        return 0;
    }
}
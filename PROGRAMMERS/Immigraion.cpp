#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long answer = 0;
    long long left = 1;
    long long right = n * (long long)times.back();
    long long mid = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;

        for (int i = 0; i < times.size(); i++) {
            cnt += mid / (long long)times[i];
        }

        if (cnt >= n) {
            right = mid - 1;
            answer = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return answer;
}

int main(){
    cout << solution(6, { 7, 10 });
}
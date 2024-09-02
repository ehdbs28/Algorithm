#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

struct Circle
{
    int start;
    int end;
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<Circle> circles;

    int data_cnt;
    cin >> data_cnt;

    for(int i = 0; i < data_cnt; i++){
        int center, radius;
        cin >> center >> radius;

        circles.push_back({center - radius, center + radius});
    }

    sort(circles.begin(), circles.end(), [](Circle a, Circle b){
        return (a.end != b.end) ? a.start < b.start : a.end < b.end;
    });

    bool isOverlap = false;
    vector<int> end_stack;

    for(Circle circle : circles){
        while(!end_stack.empty() && end_stack.back() < circle.start){
            end_stack.pop_back();
        }

        if(!end_stack.empty() && circle.start <= end_stack.back() && end_stack.back() <= circle.end){
            isOverlap = true;
            break;
        }

        end_stack.push_back(circle.end);
    }

    cout << (isOverlap ? "NO" : "YES");
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct A{
    int index;
    int value;
};

struct ASort{
    bool operator()(A& a, A& b){
        return a.value > b.value;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    priority_queue<A, vector<A>, ASort> pq;
    vector<int> nums;

    int n, l;
    int num;

    cin >> n >> l;

    for(int i = 0; i < n; i++){
        cin >> num;
        nums.push_back(num);
    }

    for(int i = 0; i < n; i++){
        pq.push({i, nums[i]});
        int pos = pq.top().index;
        while(pos < i - l + 1){
            pq.pop();
            pos = pq.top().index;
        }
        cout << pq.top().value << " ";
    }
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string charNums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<int> nums;

    int n;
    int m;

    cin >> n >> m;

    for(int i = n; i <= m; i++){
        nums.push_back(i);
    }

    sort(nums.begin(), nums.end(), [charNums](int a, int b){
        string stringA = to_string(a);
        string stringB = to_string(b);

        string k = "";
        string l = "";
        
        for(int i = 0; i < stringA.length(); i++){
            k += charNums[stringA[i] - '0'];
        }

        for(int i = 0; i < stringB.length(); i++){
            l += charNums[stringB[i] - '0'];
        }

        return k < l;
    });

    for(int i = 0; i < nums.size(); i++){
        if(i != 0 && i % 10 == 0){
            cout << "\n";
        }
        cout << nums[i] << " ";
    }
}
#include<iostream>
#include<string>

using namespace std;

int recursion(string& s, int l, int r, int& count);
int isPalindrome(string& s, int& count);

int main(){
    string input;
    int testCase, count = 0;
    cin >> testCase;

    for(int i = 0; i < testCase; i++){
        count = 0;
        cin >> input;

        cout << isPalindrome(input, count) << " " << count << "\n";
    }
}

int recursion(string& s, int l, int r, int& count){
    count++;

    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

int isPalindrome(string& s, int& count){
    return recursion(s, 0, s.length()-1, count);
}
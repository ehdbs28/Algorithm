#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string sum(string x, string y){
    int num;
	int carry = 0;
	string result;

	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	while (x.length() < y.length()) {
		x += '0';
	}
	while (x.length() > y.length()) {
		y += '0';
	}

	for (int i = 0; i < x.length(); ++i) {
		num = (x[i] - '0' + y[i] - '0' + carry) % 10;
		result += to_string(num);
		carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
	}
	if (carry != 0) {
		result += to_string(carry);
	}

	reverse(result.begin(), result.end());

	return result;
}

int main(){
    string fibo[10001] = { "0", "1", "1" };

    int n;

    cin >> n;

    for(int i = 3; i <= n; i++)
        fibo[i] = sum(fibo[i - 2], fibo[i - 1]);

    cout << fibo[n];
}
#include<iostream>
#include<algorithm>

using namespace std;

int arr[500000] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	int m;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cout << upper_bound(arr, arr + n, a) - lower_bound(arr, arr + n, a) << " ";
	}
}

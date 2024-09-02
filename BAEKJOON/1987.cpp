#include<iostream>

using namespace std;

int r;
int c;

int ans = 1;

int destX[4] = { 1, -1, 0, 0 };
int destY[4] = { 0, 0, 1, -1 };

char board[21][21] = {};
bool check[26] = {};

void DFS(int x, int y, int cnt) {
	if (check[board[y][x] - 'A']) {
		ans = max(ans, cnt);
		return;
	}

	check[board[y][x] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + destX[i];
		int ny = y + destY[i];

		if (nx < 0 || nx >= c || ny < 0 || ny >= r)
			continue;

		DFS(nx, ny, cnt + 1);
	}

	check[board[y][x] - 'A'] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < c; j++) {
			board[i][j] = line[j];
		}
	}

	DFS(0, 0, 0);

	cout << ans;
}

#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int board[1002][1002];

void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j] - 48;
        }
    }
}

void Sol() {
	for (int i = 0; i < n; i++) {
		if (board[i][0] == 1) ans = 1;
		if (board[0][i] == 1) ans = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] == 0) continue;
			board[i][j] = min(board[i - 1][j - 1], min(board[i - 1][j], board[i][j - 1])) + 1;
			ans = max(ans, board[i][j]);
		}
	}
	cout << ans * ans << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	if (n < 2 || m < 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					cout << 1 << '\n';
					return 0;
				}
				if (i == n - 1 && j == m - 1) {
					cout << 0 << '\n';
					return 0;
				}
			}
		}
	}
	Sol();
}

#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1025

using namespace std;

int N, M;
int X1, X2, Y1, Y2;
int board[MAX][MAX];
int dp[MAX][MAX]; // 1,1 부터 i,j 까지 총합

void Solution() {
	cout << dp[X2][Y2] - dp[X1 - 1][Y2] - dp[X2][Y1 - 1] + dp[X1 - 1][Y1 - 1] << endl;
}

void Setting() {
	for (int i = 2; i <= N; i++) dp[1][i] += dp[1][i - 1];
	for (int i = 2; i <= N; i++) dp[i][1] += dp[i - 1][1];
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] += dp[i][j - 1];
			dp[i][j] -= dp[i - 1][j - 1];
		}
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			dp[i][j] = board[i][j];
		}
	}
	Setting();
	for (int i = 0; i < M; i++) {
		cin >> X1 >> Y1 >> X2 >> Y2;
		Solution();
	}
}



void Solve() {
	Input();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}
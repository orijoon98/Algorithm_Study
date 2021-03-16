#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001

using namespace std;

int N, K;
int dp[MAX][MAX];

void Input() {
	cin >> N >> K;
}

void BottomUp() {
	for (int i = 1; i <= N; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	cout << dp[N][K] << endl;
}

int TopDown(int i, int j) {
	if (j == 0 || i == j) {
		return 1;
	}

	if (dp[i][j] == 0) {
		dp[i][j] = (TopDown(i - 1, j) + TopDown(i - 1, j - 1)) % 10007;
	}
	return dp[i][j];
}

void Solution() {
	BottomUp();
	//for (int i = 0; i < MAX; i++) fill(dp[i], dp[i] + MAX, 0);
	//cout << TopDown(N, K) << endl;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}
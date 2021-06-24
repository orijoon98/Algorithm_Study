#include <bits/stdc++.h>
using namespace std;
#define INF 100000000

int N;
int house[1001][3];
int dp[1001][3];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> house[i][j];
		}
	}
}

void Solution() {
	int ans = INF;

	for (int k = 0; k <= 2; k++) { // k 가 1번째 선택한 색깔
		for (int i = 0; i <= 2; i++) {
			if (i == k) {
				dp[1][i] = house[1][i];
			}
			else {
				dp[1][i] = INF;
			}
		}
		for (int i = 2; i <= N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
		}
		for (int i = 0; i <= 2; i++) {
			if (i == k) continue;
			ans = min(ans, dp[N][i]);
		}
	}
	cout << ans << '\n';
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solution();
}
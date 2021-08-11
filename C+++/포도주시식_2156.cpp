#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, ans;
int grape[10001];
int dp[10001][3]; // 0ÀÜ ¸¶½Å°æ¿ì, 1ÀÜ ¸¶½Å°æ¿ì, 2ÀÜ ¸¶½Å°æ¿ì

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> grape[i];
}

void Solution() {
	dp[1][0] = grape[1];
	dp[1][1] = grape[1];
	dp[1][2] = 0;
	ans = grape[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = grape[i] + max(dp[i - 2][0], max(dp[i - 2][1], dp[i - 2][2]));
		dp[i][1] = grape[i] + dp[i - 1][0];
		dp[i][2] = dp[i - 1][1];
		ans = max(ans, dp[i][0]);
		ans = max(ans, dp[i][1]);
		ans = max(ans, dp[i][2]);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solution();
}
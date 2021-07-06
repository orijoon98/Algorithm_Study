#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define MAX 50001

int N, able;
int customer[MAX]; // 1번부터 i번째까지 승객수 합
int dp[4][MAX];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		customer[i] = customer[i - 1] + tmp;
	}
	cin >> able;
}

void Solution() {
	for (int i = 1; i <= 3; i++) {
		for (int j = i * able; j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], customer[j] - customer[j - able] + dp[i - 1][j - able]);
		}
	}
	cout << dp[3][N] << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solution();
}
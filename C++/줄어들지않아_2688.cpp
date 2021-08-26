#include <bits/stdc++.h>
#define endl '\n'
#define MAX 65
#define ll long long

using namespace std;

int T;
ll DP[MAX][MAX]; // 오른쪽부터 i자리수가 j인 개수

void Input() {
	cin >> T;
}

void Solution() {
	for (int i = 0; i <= 9; i++) DP[1][i] = 1;
	for (int i = 2; i <= 64; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				DP[i][j] += DP[i - 1][k];
			}
		}
	}
}

void Solve() {
	Input();
	Solution();
	for (int tc = 1; tc <= T; tc++) {
		int n;
		cin >> n;
		ll ans = 0;
		for (int i = 0; i <= 9; i++) ans += DP[n][i];
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}
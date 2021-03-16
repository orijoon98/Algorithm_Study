#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T, N, target, ans;
int coin[20];
int dp[10001]; // dp[A] = B, A원을 만들 수 있는 방법의 수는 B가지

void Solution() {
	for (int i = 0; i < N; i++) {
		for (int j = coin[i]; j <= target; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[target] << endl;
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> N;
		memset(dp, 0, sizeof(dp)); dp[0] = 1;
		for (int i = 0; i < N; i++) cin >> coin[i];
		cin >> target;
		Solution();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int arr[100001];
int dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	int ans = dp[1];
	
	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
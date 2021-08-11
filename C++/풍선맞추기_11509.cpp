#include <bits/stdc++.h>
using namespace std;

int n, a, i, ans, cnt[1000001];

int main() {
	std::ios_base::sync_with_stdio(false);

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> a;
		if (!cnt[a + 1]) cnt[a]++, ans++;
		else cnt[a + 1]--, cnt[a]++;
	}

	cout << ans;

	return 0;
}
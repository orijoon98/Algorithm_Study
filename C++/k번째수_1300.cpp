#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

ll N, K;

ll smallerCnt(ll n) {
	ll cnt = 0;
	for (ll i = 1; i <= N; i++)
		if (n / i > N) cnt += N;
		else cnt += n / i;

	return cnt;
}

ll binarySearch(ll k, ll size) { // k 번째 수면 smallerCnt가 k
	ll left = 1;
	ll right = size * size;
	ll middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if (smallerCnt(middle) < k) left = middle + 1;
		else if (smallerCnt(middle) >= k) right = middle - 1;
	}
	return left;
}

void Input() {
	cin >> N >> K;
}

void Solution() {
	cout << binarySearch(K, N) << endl;
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



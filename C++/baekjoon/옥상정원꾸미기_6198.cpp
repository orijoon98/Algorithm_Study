#include <bits/stdc++.h>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

int N;
long long ans;
stack<long long> s;

void Input() {
	cin >> N;
	long long a; cin >> a;
	s.push(a);
}

void Solution() {
	for (int i = 2; i <= N; i++) {
		long long cur; cin >> cur;
		while (s.top() <= cur) {
			s.pop();
			if (s.empty()) break;
		}
		ans += s.size();
		s.push(cur);
	}
	cout << ans << endl;
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
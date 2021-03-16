#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
using namespace std;

int N;
int arr[MAX];
int P[MAX];
vector<int> LIS;
deque<int> ans;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void setAns() {
	int start;
	for (int i = N; i >= 1; i--) {
		if (P[i] == LIS.size()) start = i;
	}
	ans.push_front(arr[start]);
	int cnt = 1;
	for (int i = start - 1; i >= 1; i--) {
		if (LIS.size() - cnt == 0) break;
		if (P[i] == LIS.size() - cnt) {
			ans.push_front(arr[i]);
			cnt++;
		}
	}
}

void Solution() {
	for (int i = 1; i <= N; i++) {
		if (LIS.empty()) {
			LIS.push_back(arr[i]);
			P[i] = 1;
		}
		else if (LIS[LIS.size() - 1] < arr[i]) {
			P[i] = LIS.size() + 1;
			LIS.push_back(arr[i]);
		}
		else {
			auto p = lower_bound(LIS.begin(), LIS.end(), arr[i]);
			*p = arr[i];
			P[i] = p - LIS.begin() + 1;
		}
	}
	setAns();
	cout << LIS.size() << endl;
	for (auto cur : ans) {
		cout << cur << " ";
	}
	cout << endl;
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
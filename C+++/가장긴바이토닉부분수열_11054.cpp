#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1000
using namespace std;

int N, ans;
int A[MAX];
int Left[MAX];
int Right[MAX];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

void Solution() {
	for (int k = 0; k < N; k++) {
		Left[k] = 1;
		for (int i = 0; i < k; i++) {
			if (A[i] < A[k]) {
				Left[k] = max(Left[k], Left[i] + 1);
			}
		}
	}
	for (int k = N - 1; k >= 0; k--) {
		Right[k] = 1;
		for (int i = N - 1; i > k; i--) {
			if (A[k] > A[i]) {
				Right[k] = max(Right[k], Right[i] + 1);
			}
		}
	}
	for (int k = 0; k < N; k++) {
		ans = max(ans, Left[k] + Right[k]);
	}
	cout << ans - 1 << endl;
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
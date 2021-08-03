#include <bits/stdc++.h>
#define endl '\n'
#define MAX 50
using namespace std;

int N;
int arr[MAX];
vector<pair<int, int>> v;
set<int> ans;

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void Solution() {
	if (N == 1) {
		cout << "A" << endl;
		return;
	}
	if (N == 2) {
		if (arr[0] == arr[1])
			cout << arr[1] << endl;
		else
			cout << "A" << endl;
		return;
	}
	int a = 0;
	if(arr[1] != arr[0])
		a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	int b = arr[1] - arr[0] * a;
	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i - 1] * a + b) {
			cout << "B" << endl;
			return;
		}
	}
	cout << arr[N - 1] * a + b << endl;
}

void Solve() {
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solve();
}
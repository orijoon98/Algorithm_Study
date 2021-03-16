#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int N, M;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		arr[i] = arr[i - 1] + n;
	}
	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << arr[j] - arr[i - 1] << endl;
	}
}
#include <bits/stdc++.h>
#define endl '\n'
#define MAX 101
using namespace std;

int N, M;
int arr[MAX][MAX];

void Input() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = -1;
	}
}

void Solution() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] == arr[k][j] && arr[i][k] != 0)
					arr[i][j] = arr[i][k];
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int cnt = N - 1;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] != 0) cnt--;
		}
		cout << cnt << endl;
	}
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
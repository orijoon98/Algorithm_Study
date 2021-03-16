#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100
#define INF 987654321

using namespace std;

int N, M, cmp, ans;
int distA[MAX][MAX], distB[MAX][MAX]; // 啊涵款 规氢, 公芭款 规氢


void Input() {
	for (int i = 0; i < MAX; i++) {
		fill(distA[i], distA[i] + MAX, INF);
		fill(distB[i], distB[i] + MAX, INF);
	}
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		distA[a][b] = 1;
		distB[b][a] = 1;
	}
}

void FloydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (distA[i][k] != INF && distA[k][j] != INF) {
					if (distA[i][k] + distA[k][j] < distA[i][j]) {
						distA[i][j] = 1;
					}
				}
				if (distB[i][k] != INF && distB[k][j] != INF) {
					if (distB[i][k] + distB[k][j] < distB[i][j]) {
						distB[i][j] = 1;
					}
				}
			}
		}
	}
}

void Solution() {
	cmp = (N + 1) / 2;
	FloydWarshall();
	for (int i = 1; i <= N; i++) {
		int a = 0, b = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (distA[i][j] != INF) a++;
			if (distB[i][j] != INF) b++;
		}
		if (a >= cmp || b >= cmp) ans++;
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
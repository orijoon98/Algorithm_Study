#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define INF 987654321

int n, m;
int dist[101][101];

void Input() {
	for (int i = 0; i < 101; i++) fill(dist[i], dist[i] + 101, INF);
	cin >> n;
	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
}

void floydWarshall() {
	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void Solution() {
	floydWarshall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) cout << 0 << " ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Solution();
}
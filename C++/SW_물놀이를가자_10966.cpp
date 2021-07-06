#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int T, N, M, ans;
char board[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dist[1001][1001];

void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS() {
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 'W') {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			//Print();
			//cout << endl;
			q.push({ nx,ny });
		}
	}
}

void count() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == 'L') {
				ans += dist[i][j];
			}
		}
	}
}

void Solution() {
	cin >> T;
	for (int x = 1; x <= T; x++) {
		cin >> N >> M;
		for (int i = 0; i < 1001; i++) {
			fill(dist[i], dist[i] + 1001, -1);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> board[i][j];
			}
		}
		BFS();
		ans = 0;
		count();
		cout << "#" << x << " " << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
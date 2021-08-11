#include <bits/stdc++.h>
#define endl '\n'
#define MAX 501

using namespace std;

int N, M, ans;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
set<pair<int, int>> s;

void DFS(int x, int y, int n, int tmp) { // ÁÂÇ¥, È½¼ö, ÇÕ
	vis[x][y] = true;
	v.push_back({ x,y });
	s.insert({ x,y });
	if (n == 3) {
		for (auto cur : v) {
			for (int i = 0; i < 4; i++) {
				int X = cur.first + dx[i];
				int Y = cur.second + dy[i];
				if (X < 1 || Y < 1 || X > N || Y > M) continue;
				bool flag = false;
				for (auto cur2 : v) {
					if (cur2.first == X && cur2.second == Y) flag = true;
				}
				if (flag) continue;
				ans = max(ans, tmp + board[X][Y]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
		if (vis[nx][ny]) continue;
		DFS(nx, ny, n + 1, tmp + board[nx][ny]);
		v.pop_back();
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
}

void Setting() {
	for (auto cur : s) {
		vis[cur.first][cur.second] = false;
	}
	s.clear();
	v.clear();
}

void Solution() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DFS(i, j, 1, board[i][j]);
			Setting();
		}
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
#include <bits/stdc++.h>
using namespace std;

int R, C, ans;
char board[22][22];
bool vis[22][22];
bool alpha[26];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= C; j++) {
			board[i][j] = str[j-1];
		}
	}
}

void DFS(int x, int y, int dist) {
	ans = max(ans, dist);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || ny < 1 || nx > R || ny > C) continue; // 범위체크
		if (vis[nx][ny] == 1) continue; // 방문 체크
		if (alpha[board[nx][ny] - 65] == 1) continue; // 알파벳 체크
		vis[nx][ny] = 1;
		alpha[board[nx][ny] - 65] = 1;
		DFS(nx, ny, dist + 1);
		vis[nx][ny] = 0;
		alpha[board[nx][ny] - 65] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	vis[1][1] = 1;
	alpha[board[1][1] - 65] = 1;
	DFS(1, 1, 1);
	cout << ans;
}
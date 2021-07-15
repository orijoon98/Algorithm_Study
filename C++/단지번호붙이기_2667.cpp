#include <bits/stdc++.h>
#define endl '\n'
#define MAX 26
using namespace std;

int N, ans, cnt;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> v;

void BFS() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;
			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({ i,j });
			ans++;
			cnt = 1;
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					vis[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
			v.push_back(cnt);
		}
	}
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			board[i][j + 1] = str[j] - 48;
		}
	}
}

void Solution() {
	Input();
	BFS();
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (auto i : v) {
		cout << i << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solution();

	return 0;
}
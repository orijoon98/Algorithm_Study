#include <bits/stdc++.h>
#define endl '\n'
#define MAX 31

using namespace std;

int N, M, cnt;
int before[MAX][MAX], after[MAX][MAX];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> seperate[1000]; // 묶음 시작 인덱스
bool vis[MAX][MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> before[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> after[i][j];
		}
	}
}

void beforeBFS() { // 묶음 별로 seperate 벡터에 i,j 저장
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (vis[i][j]) continue;
			cnt++;
			int cmp = before[i][j];
			seperate[cnt].push_back({ i,j });
			queue<pair<int, int>> q;
			vis[i][j] = true;
			q.push({ i,j });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
					if (vis[nx][ny] || cmp != before[nx][ny]) continue;
					vis[nx][ny] = 1;
					q.push({ nx,ny });
					seperate[cnt].push_back({ nx,ny });
				}
			}
		}
	}
}

bool checkCPCU() {
	int changed = 0;
	for (int i = 1; i <= cnt; i++) {
		// 현재 묶음의 원래 결과
		int cmp = before[seperate[i][0].first][seperate[i][0].second];
		// 나뉜 묶음의 색이 모두 같은지 확인
		int cmpAfter = after[seperate[i][0].first][seperate[i][0].second];
		for (auto cur : seperate[i]) {
			if (after[cur.first][cur.second] != cmpAfter) return false;
		}
		if (cmpAfter != cmp) {
			changed++;
			if (changed > 1) return false;
		}
	}
	return true;
}

void Solution() {
	beforeBFS();
	if (checkCPCU()) cout << "YES" << endl;
	else cout << "NO" << endl;
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
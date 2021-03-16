#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 987654321

int N, T = 1, ans;
int board[125][125];
int dist[125][125];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void Dijkstra() {
	priority_queue<pair<int,pair<int, int>>> pq; // 비용, 정점
	pq.push({ -board[0][0],{0,0} });
	dist[0][0] = board[0][0];
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		pq.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nextX = curX + dx[dir];
			int nextY = curY + dy[dir];
			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
			int nextCost = board[nextX][nextY];
			if (dist[nextX][nextY] > cost + nextCost) {
				dist[nextX][nextY] = cost + nextCost;
				pq.push({ -dist[nextX][nextY],{nextX,nextY} });
			}
		}
	}
	ans = dist[N - 1][N - 1];
}

void Solution() {
	while (true) {
		cin >> N;
		if (N == 0) return;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < 125; i++) fill(dist[i], dist[i] + 125, INF);
		Dijkstra();
		cout << "Problem " << T++ << ": " << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}

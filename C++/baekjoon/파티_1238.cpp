#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
#define INF 1000000000
using namespace std;

int N, M, X, ans;
vector<pair<int, int>> node[MAX]; // 시간, 노드
int dist[MAX]; // 다익스트라용
int dist2[MAX][MAX]; // 플로이드워셜용

void Input() {
	cin >> N >> M >> X;
	for (int i = 0; i < MAX; i++) fill(dist2[i], dist2[i] + MAX, INF);
	for (int i = 1; i <= N; i++) dist2[i][i] = 0;
	for (int i = 1; i <= M; i++) {
		int start, finish, time;
		cin >> start >> finish >> time;
		node[start].push_back({ time, finish });
		dist2[start][finish] = time;
	}
}

void Dijkstra() { // X 에서 각각의 마을까지 최단거리
	fill(dist, dist + MAX, INF);
	priority_queue<pair<int, int>> pq;
	dist[X] = 0;
	pq.push({ 0, X });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].second;
			int nextCost = node[cur][i].first;
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

void FloydWarshall() { // 각각의 마을에서 X 까지의 최단거리
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist2[i][j] > dist2[i][k] + dist2[k][j]) {
					dist2[i][j] = dist2[i][k] + dist2[k][j];
				}
			}
		}
	}
}

void Solution() {
	Dijkstra();
	FloydWarshall();
	for (int i = 1; i <= N; i++) {
		int sum = dist[i] + dist2[i][X];
		ans = max(ans, sum);
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
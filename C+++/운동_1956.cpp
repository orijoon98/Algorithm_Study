#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 987654321

int V, E, ans = INF;
vector<pair<int,int>> edge[401]; // 거리, 정점
int dist[401];

void Dijkstra() {
	for (int i = 1; i <= V; i++) {
		fill(dist, dist + 401, INF);
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, i });
		while (!pq.empty()) {
			int cost = -pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				int nextCost = edge[cur][j].first;
				int nextCur = edge[cur][j].second;
				if (cost + nextCost < dist[nextCur]) {
					dist[nextCur] = cost + nextCost;
					pq.push({ -dist[nextCur], nextCur });
				}
			}
		}
		ans = min(ans, dist[i]);
	}
}

void Input() {
	cin >> V >> E;
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ c,b });
	}
}

void Solution() {
	Input();
	Dijkstra();
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}

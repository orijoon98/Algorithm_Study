#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
#define INF INT_MAX
using namespace std;

int n, m;
int dist[MAX];
int path[MAX];
int start, finish;
vector<pair<int, int>> node[MAX]; // 거리, 정점
vector<int> ans;

void Input() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ c,b });
	}
	cin >> start >> finish;
}

void Setting() {
	fill(dist, dist + MAX, INF);
	for (int i = 1; i <= n; i++) path[i] = i;
}

void Dijkstra() {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < node[cur].size(); i++) {
			int nextCost = node[cur][i].first;
			int next = node[cur][i].second;
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				path[next] = cur;
				pq.push({ -dist[next], next });
			}
		}
	}
}

void SearchPath() {
	int x = finish;
	while (x != path[x]) {
		ans.push_back(x);
		x = path[x];
	}
	ans.push_back(start);
	reverse(ans.begin(), ans.end());
}

void Solution() {
	Dijkstra();
	SearchPath();
	cout << dist[finish] << endl;
	cout << ans.size() << endl;
	for (auto cur : ans) {
		cout << cur << ' ';
	}
}

void Solve() {
	Input();
	Setting();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}
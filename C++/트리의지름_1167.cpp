#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int V, maximum, ans, point;

vector<pair<int, int>> edge[MAX]; // 정점, 거리

void DFS(int cur, int maximum, int prev = -1) {
	if (maximum > ans) {
		ans = maximum;
		point = cur;
	}
	for (int i = 0; i < edge[cur].size(); i++) {
		int next = edge[cur][i].first;
		int dist = edge[cur][i].second;
		if (next == prev) continue;
		DFS(next, maximum + dist, cur);
	}
}

void Input() {
	cin >> V;
	for (int i = 0; i < V; i++) {
		int a, b, c;
		cin >> a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			edge[a].push_back({ b,c });
		}
	}
}

void Solution() {
	Input();
	DFS(1, 0);
	ans = 0;
	DFS(point, 0);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Solution();
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

int n, maximum, ans, point;
vector<pair<int, int>> node[MAX];

void DFS(int cur, int maximum, int prev = -1) {
	if (maximum > ans) {
		ans = maximum;
		point = cur;
	}
	for (int i = 0; i < node[cur].size(); i++) {
		int next = node[cur][i].first;
		int dist = node[cur][i].second;
		if (next == prev) continue;
		DFS(next, maximum + dist, cur);
	}
}

void Input() {
	cin >> n;
	n--;
	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a, c });
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	DFS(1, 0);
	ans = 0;
	DFS(point, 0);
	cout << ans;
}
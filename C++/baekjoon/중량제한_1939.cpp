#include <bits/stdc++.h>
#define endl '\n'
#define MAX 10001
using namespace std;

int N, M;
int start, finish;
int maxCost, ans;
bool vis[MAX];
vector<pair<int, int>> edge[MAX];

void Setting() {
	fill(vis, vis + MAX, false);
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back({ B,C });
		edge[B].push_back({ A,C });
		maxCost = max(maxCost, C);
	}
	cin >> start >> finish;
}

bool BFS(int cost) {
	queue<int> q; // 거리, 노드
	q.push(start);
	vis[start] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == finish) return true;
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int nextCost = edge[cur][i].second;
			if (vis[next] == false && cost <= nextCost) {
				vis[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

void Solution() {
	int low = 0;
	int high = maxCost;
	while (low <= high) {
		Setting();
		int mid = (low + high) / 2;
		if (BFS(mid)) low = mid + 1;
		else high = mid - 1;
	}
	cout << high << endl;
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
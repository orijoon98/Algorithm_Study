#include <bits/stdc++.h>
#define endl '\n'
#define MAX 1001
using namespace std;

int N, M, ans;
char sex[MAX];
int root[MAX];
vector<pair<int, pair<int, int>>> edge; // 거리, 정점, 정점

int getRoot(int x) {
	if (root[x] == x) return x;
	return root[x] = getRoot(root[x]);
}

void Union(int x, int y) {
	int a = getRoot(x);
	int b = getRoot(y);
	if (a < b) root[b] = a;
	else root[a] = b;
}

bool check(int x, int y) {
	return getRoot(x) == getRoot(y);
}

void Setting() {
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}
	sort(edge.begin(), edge.end());
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> sex[i];
	}
	for (int i = 1; i <= M; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		edge.push_back({ d,{u,v} });
	}
}

void Solution() {
	for (int i = 0; i < edge.size(); i++) {
		if (sex[edge[i].second.first] != sex[edge[i].second.second]) {
			if (!check(edge[i].second.first, edge[i].second.second)) {
				Union(edge[i].second.first, edge[i].second.second);
				ans += edge[i].first;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		root[i] = getRoot(i);
	}
	for (int i = 1; i <= N; i++) {
		if (root[i] != root[1]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << ans << endl;
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
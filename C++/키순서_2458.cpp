#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int N, M, ans;
vector<int> edge[501];
vector<int> able[501]; // 각각의 정점에서 갈 수 있는 정점들
bool vis[501];

void DFS(int start, int x) {
	vis[x] = 1;
	able[start].push_back(x);
	for (int i = 0; i < edge[x].size(); i++) {
		if (!vis[edge[x][i]]) DFS(start, edge[x][i]);
	}
}

void Solution() {
	cin >> N >> M;
	while (M--) {
		int a, b; // a < b
		cin >> a >> b;
		edge[a].push_back(b); // a 에서 b로만 이동
	}
	for (int i = 1; i <= N; i++) {
		memset(vis, false, sizeof(vis));
		DFS(i, i);
	}
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		cnt += able[i].size();
		for (int j = 1; j <= N; j++) {
			if (j == i) continue;
			for (int k = 0; k < able[j].size(); k++) {
				if (able[j][k] == i) {
					cnt++;
					break;
				}
			}
		}
		if (cnt == N) ans++;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int K, V, E;
vector<int> edge[20001];
bool vis[20001], flag;
int check[20001];

void DFS(int x, int cnt) {
	vis[x] = 1;
	check[x] = cnt % 2;
	for (int i = 0; i < edge[x].size(); i++) {
		if(!vis[edge[x][i]]) DFS(edge[x][i], cnt + 1);
		else {
			if (check[edge[x][i]] == check[x]) flag = true;
		}
	}
}

void Solution() {
	cin >> K;
	while (K--) {
		memset(vis, false, sizeof(vis));
		memset(check, -1, sizeof(check));
		flag = false;
		cin >> V >> E;
		while (E--) {
			int a, b;
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (!vis[i]) DFS(i, 1);
		}
		if (flag) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		for (int i = 0; i < 20001; i++) {
			edge[i].clear();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
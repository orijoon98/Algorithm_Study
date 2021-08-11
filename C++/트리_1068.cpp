#include <bits/stdc++.h>
using namespace std;

vector<int> node[51];

int root, del, ans;

void DFS(int cur) {
	if (node[cur].empty()) { // 자식노드가 없다면
		ans++;
	}
	for (int i = 0; i < node[cur].size(); i++) {
		int next = node[cur][i];
		if (next == del) {
			if (node[cur].size() == 1) {
				ans++; //삭제된 노드만 자식이었을 경우
			}
			continue;
		}
		DFS(next);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			root = i;
			continue;
		}
		node[parent].push_back(i);
	}

	cin >> del;
	if (del == root) {
		cout << 0;
		return 0;
	}
	DFS(root);
	cout << ans;
}
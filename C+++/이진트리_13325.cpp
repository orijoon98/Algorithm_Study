#include <bits/stdc++.h>
#define endl '\n'
#define MAX (1 << 21)
using namespace std;

int k, treeSize, ans;
int tree[MAX];

void Input() {
	cin >> k;
	treeSize = 1 << (k + 1);
	for (int i = 2; i < treeSize; i++) {
		cin >> tree[i];
	}
}

int Node(int node) {
	if (node * 2 >= treeSize) {
		ans += tree[node];
		return tree[node];
	}
	else {
		int left = Node(node * 2);
		int right = Node(node * 2 + 1);
		ans += abs(left - right) + tree[node];
		return tree[node] + max(left, right);
	}
}

void Solution() {
	Node(1);
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

	return 0;
}
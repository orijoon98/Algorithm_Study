#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int N;
vector<int> edge[MAX];
int root[MAX];

void setRoot(int parent) {
	for (int i = 0; i < edge[parent].size(); i++) {
		if (root[edge[parent][i]] != 0) continue;
		root[edge[parent][i]] = parent;
		setRoot(edge[parent][i]);
	}
}

void Input() {
	cin >> N;
	for(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
}

void Solution() {
	root[1] = 1;
	setRoot(1);
	for (int i = 2; i <= N; i++) {
		if (root[i] != 0) cout << root[i] << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Input();
	Solution();
}
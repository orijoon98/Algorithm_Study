#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> node[201];
vector<int> travel;
int root[201];

void Input() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int city;
			cin >> city;
			if (city == 1) {
				node[i].push_back(j);
			}
		}
	}
	while (M--) {
		int city;
		cin >> city;
		travel.push_back(city);
	}
}

int getRoot(int city) {
	if (root[city] == city) return city;
	return getRoot(root[city]);
}

void Union(int x, int y) {
	x = getRoot(x);
	y = getRoot(y);
	if (x < y) root[y] = x;
	else root[x] = y;
}

void setRoot() {
	for (int i = 1; i <= N; i++) {
		root[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (auto cur : node[i]) {
			Union(i, cur);
		}
	}
}

void Sol() {
	/*
	cout << endl;
	for (int i = 1; i <= N; i++) {
		cout << root[i] << ' ';
	}
	cout << endl;
	*/
	int cmp = getRoot(travel[0]);
	for (auto cur : travel) {
		if (getRoot(cur) != cmp) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	Input();
	setRoot();
	Sol();
}

/*
8
5
0 1 0 0 0 0 0 0
1 0 1 0 0 0 0 0
0 1 0 0 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0
0 0 0 0 0 1 0 1
0 0 1 0 0 0 1 0
1 2 6 3 8
*/
#include <bits/stdc++.h>
#define endl '\n'
#define MAX 100001
using namespace std;

int N, K;
int board[MAX];
int dist[MAX];
int before[MAX];

void Input() {
	cin >> N >> K;
}

void BFS() {
	fill(dist, dist + MAX, -1);
	fill(before, before + MAX, -1);
	queue<int> q;
	dist[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int next;
		for (int i = 0; i < 3; i++) {
			if (i == 0) next = cur - 1;
			else if (i == 1) next = cur + 1;
			else next = cur * 2;
			if (next < 0 || next > 100000) continue;
			if (dist[next] >= 0) continue;
			dist[next] = dist[cur] + 1;
			q.push(next);
			before[next] = cur;
			if (next == K) return;
		}
	}
}

void Solution() {
	BFS();
	cout << dist[K] << endl;
	if (N == K) {
		cout << N << endl;
		return;
	}
	int bef = K;
	deque<int> d;
	d.push_back(K);
	while (true) {
		bef = before[bef];
		if (bef == N) break;
		d.push_front(bef);
	}
	d.push_front(N);
	for (auto cur : d) {
		cout << cur << ' ';
	}
	cout << endl;
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
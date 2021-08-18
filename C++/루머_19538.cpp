#include <bits/stdc++.h>
#define endl '\n'
#define MAX 200001

using namespace std;

int N, M;
int ans[MAX];
vector<int> V[MAX];
vector<int> D;


void Setting() {
	fill(ans, ans + MAX, -1);
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		while (true) {
			int n;
			cin >> n;
			if (n == 0) break;
			V[i].push_back(n);
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int n;
		cin >> n;
		D.push_back(n);
		ans[n] = 0;
	}
}

void Solution() {
	queue<pair<int, int>> q; // 다음 노드, 시간
	for (int i = 0; i < D.size(); i++) {
		q.push({ D[i], 0 });
	}
	while (!q.empty()) {
		int curNode = q.front().first;
		int curTime = q.front().second;
		if (ans[curNode] != -1) { // 믿고 있다면
			ans[curNode] = min(curTime, ans[curNode]);
		}
		else {
			ans[curNode] = curTime;
		}
		q.pop();
		for (int i = 0; i < V[curNode].size(); i++) {
			int nextNode = V[curNode][i];
			if (ans[nextNode] >= 0) continue; // 이미 믿고있다면 스킵
			int isRumer = 0;
			for (int i = 0; i < V[nextNode].size(); i++) {
				if (ans[V[nextNode][i]] >= 0) isRumer++;
			}
			if (!(isRumer || V[nextNode].size())) continue;
			if (V[nextNode].size() <= isRumer * 2) {
				q.push({ nextNode, curTime + 1 });
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
}

void Solve() {
	Setting();
	Input();
	Solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
}
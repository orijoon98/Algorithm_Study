#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 987654321

int n;
double ans = 0;
vector<pair<double, double>> star;
vector<pair<int, double>> edge[100]; // 정점, 거리
double dist[100];
bool vis[100];

void Input() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		double a, b;
		cin >> a >> b;
		star.push_back({ a,b });
	}
}

void Setting() { // 간선의 길이 세팅
	for (int i = 0; i < star.size(); i++) {
		for (int j = 0; j < star.size(); j++) {
			if (j == i) continue;
			double distance = sqrt(pow(star[i].first - star[j].first, 2) + pow(star[i].second - star[j].second, 2));
			edge[i].push_back({ j,distance });
		}
	}
	fill(dist, dist + 100, INF);
}

void Prim() {
	dist[0] = 0;
	vis[0] = true;
	for (int i = 0; i < edge[0].size(); i++) {
		int next = edge[0][i].first;
		double distance = edge[0][i].second;
		dist[next] = distance;
	}
	for (int i = 1; i <= n - 1; i++) {
		double minCost = INF;
		int minIndex = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j]) continue;
			if (minCost > dist[j]) {
				minCost = dist[j];
				minIndex = j;
			}
		}
		vis[minIndex] = true;
		ans += minCost;
		for (int j = 0; j < edge[minIndex].size(); j++) {
			int next = edge[minIndex][j].first;
			double distance = edge[minIndex][j].second;
			if (vis[next]) continue;
			if (dist[next] > distance) dist[next] = distance;
		}
	}
}

void Solution() {
	Input();
	Setting();
	Prim();
	cout.precision(3);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 801
#define INF 1e9

int N, E, x, y, Answer;
vector<pair<int, int>> node[MAX];
bool vis[MAX];
int dist[MAX];


void Input() {
	cin >> N >> E;
	while (E--) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	cin >> x >> y;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].first;
			int nCost = node[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push({ -1 * dist[next], next });
			}
		}
	}
}

void Solution()
{
	bool Flag1, Flag2;
	Flag1 = Flag2 = true;

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dijkstra(1);
	int Route1 = dist[x];
	int Route2 = dist[y];
	if (Route1 == INF) Flag1 = false;
	if (Route2 == INF) Flag2 = false;

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dijkstra(x);
	if (Flag1 == true) Route1 = Route1 + dist[y];
	if (Flag2 == true) Route2 = Route2 + dist[y];

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dijkstra(y);
	if (Flag1 == true) Route1 = Route1 + dist[N];

	for (int i = 1; i <= N; i++) dist[i] = INF;
	dijkstra(x);
	if (Flag2 == true) Route2 = Route2 + dist[N];

	if (Flag1 == false && Flag2 == false) Answer = -1;
	else
	{
		Answer = min(Route1, Route2);
	}

	if (Answer == INF) Answer = -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solution();
	cout << Answer << '\n';
}
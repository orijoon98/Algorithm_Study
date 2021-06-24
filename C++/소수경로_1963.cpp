#include <bits/stdc++.h>
using namespace std;
#define thousand /1000
#define hundred %1000/100
#define ten %100/10
#define one %10

int ans;
int dist[10000];
bool able;

bool isPrime(int number) {
	for (int i = 2; i < number; i++) {
		if (number % i == 0) return false;
	}
	return true;
}

void BFS(int start, int finish) {
	if (start == finish) {
		able = true;
		ans = 0;
		return;
	}
	queue<int> q;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int cur_thousand = cur thousand;
		int cur_hundrend = cur hundred;
		int cur_ten = cur ten;
		int cur_one = cur one;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				int new_thousand, new_hundred, new_ten, new_one, newNum;
				switch (i) {
				case 0:
					new_thousand = j;
					newNum = new_thousand * 1000 + cur_hundrend * 100 + cur_ten * 10 + cur_one * 1;
					break;
				case 1:
					new_hundred = j;
					newNum = cur_thousand * 1000 + new_hundred * 100 + cur_ten * 10 + cur_one * 1;
					break;
				case 2:
					new_ten = j;
					newNum = cur_thousand * 1000 + cur_hundrend * 100 + new_ten * 10 + cur_one * 1;
					break;
				default: // case 3:
					new_one = j;
					newNum = cur_thousand * 1000 + cur_hundrend * 100 + cur_ten * 10 + new_one * 1;
					break;
				}
				if (newNum == finish) {
					able = true;
					dist[newNum] = dist[cur] + 1;
					ans = dist[newNum];
					return;
				}
				if (newNum / 1000 == 0) continue;
				if (dist[newNum] >= 0) continue;
				if (isPrime(newNum) == false) continue;
				dist[newNum] = dist[cur] + 1;
				q.push(newNum);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		ans = 0;
		able = false;
		fill(dist, dist + 10000, -1);
		BFS(a, b);
		if (able) {
			cout << ans << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}	
	}
}
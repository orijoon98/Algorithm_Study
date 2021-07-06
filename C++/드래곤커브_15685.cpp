#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int N, ans;
int board[101][101];
vector<pair<int, int>> dragon;

void dragonCurve() {
	int n = dragon.size();
	int x = dragon[n - 1].first;
	int y = dragon[n - 1].second;
	for (int i = n - 2; i >= 0; i--) {
		int a = dragon[i].first;
		int b = dragon[i].second;
		int A = x - y + b;
		int B = x + y - a;
		board[A][B] = 1;
		dragon.push_back({ A,B });
	}
}

void Print() {
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl; 
}

bool checkSquare(int x, int y) {
	for (int i = x; i <= x + 1; i++) {
		for (int j = y; j <= y + 1; j++) {
			if (board[i][j] == 0) return false;
		}
	}
	return true;
}

void Solution() {
	cin >> N;
	while (N--) {
		dragon.clear();
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		board[y][x] = 1;
		dragon.push_back({ y,x });
		switch (d) {
		case 0:
			board[y][x + 1] = 1;
			dragon.push_back({ y, x + 1 });
			break;
		case 1:
			board[y - 1][x] = 1;
			dragon.push_back({ y - 1, x });
			break;
		case 2:
			board[y][x - 1] = 1;
			dragon.push_back({ y, x - 1 });
			break;
		case 3:
			board[y + 1][x] = 1;
			dragon.push_back({ y + 1, x });
			break;
		}
		for (int i = 1; i <= g; i++) {
			dragonCurve();
		}
	}
	//Print();
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (checkSquare(i, j)) ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
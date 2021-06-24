#include <bits/stdc++.h>
using namespace std;

int board[10][10];
vector<pair<int, int>> v;
bool flag;

void Input() {
	for (int i = 1; i <= 9; i++) {
		string inputNum;
		cin >> inputNum;
		for (int j = 0; j < 9; j++) {
			board[i][j + 1] = inputNum[j] - 48;
			if (board[i][j + 1] == 0) v.push_back({ i,j + 1 });
		}
	}
}

void Output() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

bool checkCol(int x, int y, int target) {
	for (int i = 1; i <= 9; i++) {
		if (board[i][y] == target) return false;
	}
	return true;
}

bool checkRow(int x, int y, int target) {
	for (int i = 1; i <= 9; i++) {
		if (board[x][i] == target) return false;
	}
	return true;
}

bool checkSquare(int x, int y, int target) {
	int a = (x - 1) / 3;
	int b = (y - 1) / 3;
	for (int i = a * 3 + 1; i <= a * 3 + 3; i++) {
		for (int j = b * 3 + 1; j <= b * 3 + 3; j++) {
			if (board[i][j] == target) return false;
		}
	}
	return true;
}

bool checkAll(int x, int y, int target) {
	if (checkCol(x, y, target) && checkRow(x, y, target) && checkSquare(x, y, target)) return true;
	else return false;
}

void Track(int n) {
	if (!flag) {
		if (n == v.size()) {
			flag = true;
			Output();
			return;
		}
		int x = v[n].first;
		int y = v[n].second;
		for (int i = 1; i <= 9; i++) {
			if (checkAll(x, y, i)) {
				board[x][y] = i;
				Track(n + 1);
				board[x][y] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Track(0);
}
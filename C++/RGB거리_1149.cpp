#include <bits/stdc++.h>
using namespace std;

int N;
int house[1001][3];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + a;
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + b;
		house[i][2] = min(house[i - 1][0], house[i - 1][1]) + c;
	}
}

void Solution() {
	cout << min(house[N][2], min(house[N][0], house[N][1]));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Input();
	Solution();
}
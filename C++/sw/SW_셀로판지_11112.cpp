#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int T, p, q, r, a, b, c, d;

//원의 중심이 직사각형 안에 있는지 확인
bool circleInSquare(int p, int q, int a, int b, int c, int d) {
	if (a <= p && p <= c && b <= q && q <= d) return true;
	return false;
}

void Solution() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> p >> q >> r;
		cin >> a >> b >> c >> d;
		int x = 987654321, X = 0; // x는 원의 중심에서 직사각형까지 최소거리, X는 최대거리
		x = min(x, abs(p - a));
		x = min(x, abs(p - c));
		x = min(x, abs(q - b));
		x = min(x, abs(q - d)); // 직사각형의 변까지의 거리중 최소
		x *= x;
		X = max(X, (p - a) * (p - a) + (q - b) * (q - b));
		X = max(X, (p - a) * (p - a) + (q - d) * (q - d));
		X = max(X, (p - c) * (p - c) + (q - b) * (q - b));
		X = max(X, (p - c) * (p - c) + (q - d) * (q - d)); // 각 꼭짓점까지의 거리 중 최대
		if (circleInSquare(p, q, a, b, c, d)) {
			cout << "#" << i << " ";
			if (r * r <= x) cout << "N";
			else cout << "Y";
			if (r * r >= X) cout << "N";
			else cout << "Y";
			cout << endl;
		}
		else { // 원의 중심이 직사각형 밖에 있다면
			cout << "#" << i << " ";
			cout << "Y"; // 원은 무조건 보인다
			if (r * r >= X) cout << "N";
			else cout << "Y";
			cout << endl;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}
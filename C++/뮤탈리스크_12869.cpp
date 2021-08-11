#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int N;
int scv[3];
int dp[61][61][61];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> scv[i];
	}
	memset(dp, -1, sizeof(dp));
}

int solution(int x, int y, int z) {
	//파괴된 SCV가 있을 경우
	if (x < 0)return solution(0, y, z);
	if (y < 0)return solution(x, 0, z);
	if (z < 0)return solution(x, y, 0);

	//모든 SCV가 파괴된 경우
	if (x == 0 && y == 0 && z == 0)
		return 0;

	int& res = dp[x][y][z];

	//이미 구해둔 값이면
	if (res != -1)
		return res;

	res = 99999999;
	res = min(res, solution(x - 9, y - 3, z - 1) + 1);
	res = min(res, solution(x - 9, y - 1, z - 3) + 1);
	res = min(res, solution(x - 3, y - 9, z - 1) + 1);
	res = min(res, solution(x - 1, y - 9, z - 3) + 1);
	res = min(res, solution(x - 3, y - 1, z - 9) + 1);
	res = min(res, solution(x - 1, y - 3, z - 9) + 1);

	return res;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	cout << solution(scv[0], scv[1], scv[2]) << endl;
}
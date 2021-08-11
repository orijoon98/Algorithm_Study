#include <iostream>
#define endl '\n'
using namespace std;

string str;
int cnt[10];
int ans;

void Input() {
	cin >> str;
}

void Solution() {
	for (int i = 0; i < str.size(); i++) {
		cnt[str[i] - 48]++;   
	}
	if ((cnt[9] + cnt[6]) % 2 == 0) {
		cnt[6] = (cnt[9] + cnt[6]) / 2;
		cnt[9] = 0;
	} 
	else {
		cnt[6] = (cnt[9] + cnt[6]) / 2 + 1;
		cnt[9] = 0;
	}
	for (int i = 0; i < 9; i++) {
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
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
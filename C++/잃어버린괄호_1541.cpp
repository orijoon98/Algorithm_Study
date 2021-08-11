#include <bits/stdc++.h>
#define endl '\n'
#define MAX INT_MAX

using namespace std;

string str;
deque<char> Operator;
deque<int> Operand;
vector<int> OperatorV;
int ans;

void Input() {
	cin >> str;
}

void Solution() {
	int cur = 0, tmp = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] != '+' && str[i] != '-') { // 피연산자
			cur += tmp * (str[i] - 48);
			tmp *= 10;
			if (i == 0) Operand.push_front(cur);
		}
		else { // 연산자
			Operator.push_front(str[i]);
			Operand.push_front(cur);
			cur = 0;
			tmp = 1;
		}
	}
	for (auto cur : Operator) OperatorV.push_back(cur);
	// - 이후에 등장하는 +들은 다음 -가 나올때까지 모두 -로 변경
	for (int i = 0; i < OperatorV.size(); i++) {
		if (OperatorV[i] == '-') {
			while (true) {
				if (i + 1 == OperatorV.size()) break;
				if (OperatorV[i + 1] == '+') {
					OperatorV[i + 1] = '-';
					i++;
				}
				else break;
			}
		}
	}
	// 계산하기
	ans = Operand.at(0);
	for (int i = 0; i < OperatorV.size(); i++) {
		if (OperatorV[i] == '+') {
			ans += Operand.at(i + 1);
		}
		else {
			ans -= Operand.at(i + 1);
		}
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
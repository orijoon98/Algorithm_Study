#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T, n;
string p, str;
string numbers[400001];
deque<int> dq;
vector<int> v;
bool flag = true;

void Function(int n) {
	if (n == 1) { // r이 홀수 일때
		string newStr = "[";
		for (auto cur : dq) {
			v.push_back(cur);
		}
		for (int i = v.size() - 1; i >= 0; i--) {
			newStr += to_string(v[i]);
			newStr += ',';
		}
		if(newStr[newStr.size() - 1] == ',') newStr[newStr.size() - 1] = ']';
		else newStr += ']';
		str = newStr;
	}
	else { // r이 짝수일때
		string newStr = "[";
		for (auto cur : dq) {
			newStr += to_string(cur);
			newStr += ',';
		}
		if (newStr[newStr.size() - 1] == ',') newStr[newStr.size() - 1] = ']';
		else newStr += ']';
		str = newStr;
	}
}

void Solution() {
	cin >> T;
	while (T--) {
		cin >> p;
		cin >> n;
		cin >> str;
		flag = true;
		int j = 0;
		fill(numbers, numbers + 400001, "");
		dq.clear();
		v.clear();
		if (n != 0) {
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '[' || str[i] == ']') continue;
				if (str[i] == ',') {
					j++;
					continue;
				}
				numbers[j] += str[i];
			}
			for (int i = 0; i <= j; i++) dq.push_back(stoi(numbers[i]));
		}
		int r = 0, d1 = 0, d2 = 0; // R의 개수, R이 짝수일때, R이 홀수일때
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') r++;
			else { // 'D'
				if (r % 2 == 0) d1++;
				else d2++;
			}
		}
		for (int i = 0; i < d1; i++) {
			if (dq.empty()) flag = false;
			if(flag) dq.pop_front();
			if (!flag) break;
		}
		for (int i = 0; i < d2; i++) {
			if (dq.empty()) flag = false;
			if (flag) dq.pop_back();
			if (!flag) break;
		}
		if (!flag) cout << "error" << endl;
		else if (r % 2 == 1) {
			Function(1);
			cout << str << endl;
		}
		else {
			Function(0);
			cout << str << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solution();
}

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int number) {
	if (number == 1) return false;
	for (int i = 2; i < number; i++) {
		if (number % i == 0) return false;
	}
	return true;
}

bool isPal(int number) {
	string strNum = to_string(number);
	for (int i = 0; i < strNum.size(); i++) {
		if (strNum[i] != strNum[strNum.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	while (true) {
		if (isPal(n) && isPrime(n)) break;
		n++;
	}
	cout << n << '\n';
}
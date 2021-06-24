#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string word, explode;
	cin >> word >> explode;
	
	vector<pair<char, int>> v;
	
	for (int i = 0; i < word.size(); i++) {
		for (int j = 0; j < explode.size(); j++) {
			if (word[i] == explode[j]) {
				v.push_back({ word[i],i });
				if (j == explode.size() - 1) {
					int t = explode.size() - 1;
					for (int k = v.size() - 1; k >= v.size() - explode.size(); k--) {
						if (k < 0 || t < 0) break; 
						if (v[k].first != explode[t]) break;
						if (t == 0) {
							bool explodeOrNot = true;
							for (int g = 1; g < explode.size(); g++) {
								int change = v[v.size() - g].second;
								int next = v[v.size() - g - 1].second;
								for (int x = next + 1; x < change; x++) {
									for (int y = 0; y < explode.size(); y++) {
										if (word[x] == '.') continue;
										if (word[x] != explode[y]) explodeOrNot = false;
									}
								}
							}
							if (explodeOrNot) {
								for (int g = 0; g < explode.size(); g++) {
									int change = v[v.size() - 1].second;
									word[change] = '.';
									v.pop_back();
								}
							}
						}
						t--;
					}
				}
				break;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] != '.') {
			flag = true;
			cout << word[i];
		}
	}
	if (!flag) cout << "FRULA";
}
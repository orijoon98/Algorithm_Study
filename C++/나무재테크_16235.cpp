#include <bits/stdc++.h>
#define endl '\n'
#define MAX 11
using namespace std;

int N, M, K;
int ans;
int board[MAX][MAX]; // ¾çºÐ
int S2D2[MAX][MAX];
vector<int> age[MAX][MAX];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S2D2[i][j];
			board[i][j] = 5;
		}
	}
	for (int i = 1; i <= M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		age[x][y].push_back(z);
	}
}

void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void SpringAndSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (age[i][j].size() == 0) continue;
			int deadTreeEnergy = 0;
			vector<int> temp;
			sort(age[i][j].begin(), age[i][j].end());
			for (int k = 0; k < age[i][j].size(); k++) {
				int Age = age[i][j][k];
				if (board[i][j] >= Age) {
					board[i][j] -= Age;
					temp.push_back(Age + 1);
				}
				else {
					deadTreeEnergy += Age / 2;
				}
			}
			age[i][j].clear();
			for (int k = 0; k < temp.size(); k++) {
				age[i][j].push_back(temp[k]);
			}
			board[i][j] += deadTreeEnergy;
		}
	}
}

void Autumn() {
	for(int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (age[i][j].size() == 0) continue;
			for (int k = 0; k < age[i][j].size(); k++) {
				int Age = age[i][j][k];
				if (Age % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						int nx = i + dx[a];
						int ny = j + dy[a];
						if (nx >= 1 && ny >= 1 && nx <= N && ny <= N) {
							age[nx][ny].push_back(1);
						}
					}
				}
			}
		}
	}
}

void Winter() {
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= N; j++) {
			board[i][j] += S2D2[i][j];
		}
	}
}

void Year() {
	SpringAndSummer();
	Autumn();
	Winter();
}

void Solution() {
	while (K--) {
		Year();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += age[i][j].size();
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
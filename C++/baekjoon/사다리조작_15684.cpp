#include <bits/stdc++.h>
using namespace std;

int N, M, H, ans;
int board[11][31];
bool vis[11][31];

void Input() {
	ans = 9999999;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vis[b][a] = true;
	}
}

bool game() {
    for (int i = 1; i <= N; i++)
    {
        int cur = i;
        for (int j = 1; j <= H; j++)
        {
            if (vis[cur][j] == true) cur = cur + 1;
            else if (vis[cur - 1][j] == true) cur = cur - 1;
        }

        if (cur != i) return false;
    }
    return true;
}

void track(int idx, int cnt) {
    if (cnt >= 4) return;
    if (game() == true) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            if (vis[j][i] == true) continue;
            if (vis[j - 1][i] == true) continue;
            if (vis[j + 1][i] == true) continue;

            vis[j][i] = true;
            track(i, cnt + 1);
            vis[j][i] = false;
        }
    }
}


void solution() {
    track(1, 0);
    if (ans == 9999999) ans = -1;
    cout << ans << '\n';
}

void sol() {
    Input();
    solution();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    sol();
}
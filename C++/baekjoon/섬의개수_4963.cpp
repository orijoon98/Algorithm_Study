#include <bits/stdc++.h>
#define endl '\n'
#define MAX 50

using namespace std;

int w, h;
int board[MAX][MAX];
bool vis[MAX][MAX];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void DFS(pair<int,int> cur) {
    vis[cur.first][cur.second] = true;
    for (int dir = 0; dir < 8; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if (board[nx][ny] == 0) continue;
        if (vis[nx][ny]) continue;
        DFS({nx,ny});
    }
}

int Solution() {
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j] && board[i][j] == 1) {
                DFS({i,j});
                ans++;
            }
        }
    }
    return ans;
}

void Input() {
    while (true) {
        memset(board, 0, sizeof(board));
        memset(vis, false, sizeof(vis));
        cin>>w>>h;
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin>>board[i][j];
            }
        }
        cout<<Solution()<<endl;
    }
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

    return 0;
}
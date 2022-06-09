#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, M, ans = 0;
int board[1001][1001];
int dist[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

void Initialization() {
    memset(dist, -1, sizeof(dist));
}

void Input() {
    cin>>M>>N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin>>board[i][j];
            if (board[i][j] == 1) {
                dist[i][j] = 0;
                Q.push({i,j});
            }
        }
    }
}

bool Check() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] == 0)
                return true;
        }
    }
    return false;
}

void Solution() {
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if (board[nx][ny] == -1) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            board[nx][ny] = 1;
            Q.push({nx,ny});
            ans = max(ans, dist[nx][ny]);
        }
    }
    if (Check()) cout<<"-1"<<endl;
    else cout<<ans<<endl;
}

void Solve() {
    Initialization();
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
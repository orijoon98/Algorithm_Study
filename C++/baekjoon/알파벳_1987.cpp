#include <bits/stdc++.h>
#define endl '\n'
#define MAX 21

using namespace std;

int R, C, ans = 0;
bool alphabetVis[26];
bool vis[MAX][MAX];
char board[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Input() {
    cin>>R>>C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin>>board[i][j];       
        }
    }
}

void DFS(pair<int,int> cur, int result) {
    ans = max(ans, result);
    for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
        if (vis[nx][ny]) continue;
        char alphabet = board[nx][ny];
        int index = alphabet - 'A';
        if (alphabetVis[index]) continue;
        vis[nx][ny] = true;
        alphabetVis[index] = true;
        DFS({nx,ny}, result + 1);
        vis[nx][ny] = false;
        alphabetVis[index] = false;
    }
}

void Solution() {
    char alphabet = board[1][1];
    int index = alphabet - 'A';
    alphabetVis[index] = true;
    vis[1][1] = true;
    DFS({1,1}, 1);
    cout<<ans<<endl;
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
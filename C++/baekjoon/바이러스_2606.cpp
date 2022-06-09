#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

int board[101][101];
bool vis[101];
int n, m, ans = 0;

void Input() {
    cin>>n;
    cin>>m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = 1;
    }   
}

void Solution() {
    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int i = 1; i <= 100; i++) {
            if (board[cur][i] != 1) continue;
            int next = i;
            if (vis[next]) continue;
            vis[next] = 1;
            ans++;
            Q.push(next);
        }        
    }
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


#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int dist[301][301];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int T, I;

void Initialization() {
    memset(dist, -1, sizeof(dist));
}

int Solution(int I, pair<int,int> start, pair<int,int> end) {
    if (start.first == end.first && start.second == end.second) 
        return 0;
    queue<pair<int,int>> Q;
    dist[start.first][start.second] = 0;
    Q.push(start);
    while (!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 8; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx == end.first && ny == end.second) 
                return dist[cur.first][cur.second] + 1;
            if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
            if (dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    return -1;
}

void Input() {
    cin>>T;
    for (int i = 0; i < T; i++) {
        Initialization();
        cin>>I;
        int a, b, c, d;
        cin>>a>>b;
        cin>>c>>d;
        pair<int,int> start = {a,b};
        pair<int,int> end = {c,d};
        cout<<Solution(I, start, end)<<endl;
    }
}

void Solve() {
    Input();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
//시간초과 코드

//#include<bits/stdc++.h>
//using namespace std;
//#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//
//int board[1001][1001];
//vector<pair<int, int>> wall; // 벽의 위치 저장하는 벡터
//int dist[1001][1001];
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//
//int bfs(int n, int m){
//    queue<pair<int,int>> q;
//    dist[1][1] = 1;
//    q.push({1,1});
//    while(!q.empty()){
//        auto cur = q.front(); q.pop();
//        if(cur.first == n && cur.second == m){
//            return dist[cur.first][cur.second];
//        }
//        for(int dir=0;dir<4;dir++){
//            int nx = cur.first + dx[dir];
//            int ny = cur.second + dy[dir];
//            if(nx == n && ny == m){
//                return dist[cur.first][cur.second] + 1;
//            }
//            if(nx<1 || ny<1 || nx>n || ny>m) continue;
//            if(board[nx][ny] == 1 || dist[nx][ny] >= 1) continue;
//            dist[nx][ny] = dist[cur.first][cur.second] + 1;
//            q.push({nx,ny});
//        }
//    }
//    return -1;
//}
//
//int main() {
//    FAST;
//    int n, m; cin>>n>>m;
//    for(int i=1;i<=n;i++){
//        string str;
//        cin>>str;
//        for(int j=0;j<m;j++){
//            board[i][j+1] = str[j] - 48;
//            if(board[i][j+1] == 1) wall.push_back({i,j+1});
//        }
//    }
//
//    int ans = 10000000;
//    bool flag = false; // bfs가 -1이 아닌 경우가 한번이라도 나오면 true
//    //벽을 뚫지 않았을 때 BFS
//    int a = bfs(n, m);
//    for(int i=1;i<=n;i++) fill(dist[i], dist[i]+m+1, 0);
//    if(a != -1) flag = true;
//    if(flag) ans = min(ans, a);
//    //벽을 번갈아가면서 하나씩 0으로 바꾸고 BFS 이후 다시 1로 바꾼다
//    bool flag2 = false;
//    for(auto w: wall){
//        board[w.first][w.second] = 0;
//        a = bfs(n, m);
//        for(int i=1;i<=n;i++) fill(dist[i], dist[i]+m+1, 0);
//        if(a != -1){
//            flag = true;
//            flag2 = true;
//        }
//        else flag2 = false;
//        if(flag2) ans = min(ans, a);
//        board[w.first][w.second] = 1;
//    }
//    //최단거리 출력
//    if(flag) cout<<ans;
//    else cout<<-1;
//}

#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[1001][1001];
int dist[1001][1001][2]; // 벽을 부셨는지 여부도 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
    FAST;
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            board[i][j+1] = str[j] - 48;
        }
    }
    queue<tuple<int, int, int>> q;
    dist[1][1][0] = 1;
    q.push(make_tuple(1, 1, 0)); //0이면 벽을 안 부신 상태
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int crash = get<2>(q.front());
        q.pop();
        if(x == n && y == m){
            cout<<dist[n][m][crash]<<'\n';
            return 0;
        }
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx == n && ny == m){
                cout<<dist[x][y][crash] + 1<<'\n';
                return 0;
            }
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(board[nx][ny] == 1 && crash == 0){
                dist[nx][ny][1] = dist[x][y][crash] + 1;
                q.push(make_tuple(nx, ny, 1));
            }
            if(board[nx][ny] == 0 && dist[nx][ny][crash] == 0){
                dist[nx][ny][crash] = dist[x][y][crash] + 1;
                q.push(make_tuple(nx, ny, crash));
            }
        }
    }
    cout<<-1<<'\n';
}

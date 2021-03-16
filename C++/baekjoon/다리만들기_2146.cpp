#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int num, int n){ // num 번호 섬에서 다리놓기
    int ans = 100000; // 다리길이
    queue<pair<int,int>> q;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j] == num){
                q.push({i,j});
                dist[i][j] = 0; // 방문 처리
            }
        }
    }
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<1 || ny<1 || nx>n || ny>n) continue;
            if(board[nx][ny] == num || dist[nx][ny] >= 0) continue; // 같은 섬이거나 이미 방문했으면 continue
            if(board[nx][ny] >= 1){
                ans = min(ans, dist[cur.first][cur.second]);
            }
            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 방문처리
            q.push({nx,ny});
        }
    }
    return ans;
}

int main() {
    FAST;
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j] = -1;
            cin>>board[i][j];
            if(board[i][j] == 1) board[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    int num = 0;
    // 섬 번호 구분
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j] == -1){
                q.push({i,j});
                num++;
                board[i][j] = num;
            }
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<1 || ny<1 || nx>n || ny>n) continue;
                    if(board[nx][ny] == 0 || board[nx][ny] >= 1) continue;
                    board[nx][ny] = num;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    int ans = 100000;
    for(int i=1;i<=num;i++){
        for(int j=1;j<=n;j++) fill(dist[j], dist[j]+n+1, -1);
        ans = min(ans, bfs(i, n));
    }
    cout<<ans;
}

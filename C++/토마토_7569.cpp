#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define X first.first
#define Y first.second
#define Z second

int board[101][101][101];
int dist[101][101][101];
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

int main() {
    FAST;
    int M, N, H;
    cin>>M>>N>>H;
    queue<pair<pair<int, int>, int>> Q;
    int cnt = 0;
    for(int k=1;k<=H;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                dist[i][j][k] = -1;
                cin>>board[i][j][k];
                if(board[i][j][k] == 1){ // 익은 토마토를 시작점으로 큐에 넣어준다
                    Q.push({{i,j},k});
                    dist[i][j][k] = 0;
                }
                if(board[i][j][k] == 0) cnt++; // 안 익은 토마토 개수 카운트
            }
        }
    }
    if(cnt == 0){ // 토마토가 모두 익어있으면 0 출력하고 종료
        cout<<0<<'\n';
        return 0;
    }
    int mx = 0;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<6;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int nz = cur.Z + dz[dir];
            if(nx<1 || ny<1 || nz<1 || nx>N || ny>M || nz>H) continue; // 범위 체크
            if(board[nx][ny][nz] == -1 || dist[nx][ny][nz] >= 0) continue; // 토마토 유무, 이미 익었는지 체크
            dist[nx][ny][nz] = dist[cur.X][cur.Y][cur.Z] + 1;
            Q.push({{nx,ny},nz});
            
            mx = max(mx, dist[nx][ny][nz]);
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=1;k<=H;k++){
                if(board[i][j][k] == 0 && dist[i][j][k] == -1){ // 안 익은 토마토가 남아있는 경우 체크
                    cout<<-1<<'\n';
                    return 0;
                }
            }
        }
    }
    cout<<mx<<'\n'; // 최소 일수 출력
}

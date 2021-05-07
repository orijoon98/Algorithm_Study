#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int board[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    FAST;
    bool visit[500][500];
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
            visit[i][j] = 0;
        }
    }
    int mx = 0, num = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 0 || visit[i][j] == 1) continue;
            num++;
            queue<pair<int,int>> Q;
            visit[i][j] = 1;
            Q.push({i,j});
            int area = 0;
            while(!Q.empty()){
                area++;
                pair<int,int> cur = Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
                    visit[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            mx = max(mx, area);
        }
    }
    cout<<num<<'\n'<<mx<<'\n';
}

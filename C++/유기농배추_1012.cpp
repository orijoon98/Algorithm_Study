#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[50][50];
int vis[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    FAST;
    int T;
    cin>>T;
    while(T--){
        for(int i=0;i<50;i++){
            fill(board[i], board[i]+50, 0);
            fill(vis[i], vis[i]+50, 0);
        }
        int M, N, K;
        cin>>M>>N>>K;
        while(K--){
            int a, b;
            cin>>a>>b;
            board[b][a] = 1;
        }
        queue<pair<int, int>> Q;
        int cnt = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(board[i][j] == 1 && vis[i][j] != 1){
                    vis[i][j] = 1;
                    Q.push({i,j});
                    cnt++;
                    while(!Q.empty()){
                        auto cur = Q.front(); Q.pop();
                        for(int dir=0;dir<4;dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;
                            if(vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
}

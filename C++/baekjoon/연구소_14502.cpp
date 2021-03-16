#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, M, cnt, space, ans;
int board[10][10];
bool changed[10][10];
int vis[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
//int check;

void input(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>board[i][j];
            if(board[i][j] == 0) space++; // 빈 칸의 개수
        }
    }
}

void BFS(){ // 바이러스 전파
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j] == 2){ // 바이러스인 곳에서 시작
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 1 || ny < 1 || nx > N || ny > M) continue; // 범위 체크
                        if(board[nx][ny] == 1 || board[nx][ny] == 2) continue; // 벽이거나 바이러스면 continue
                        if(vis[nx][ny] == 1) continue; // 이미 방문했으면 continue
                        cnt++; // 빈 칸이 바이러스로 전파된 개수
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }

}

void wall(int n){ // 벽세우기
    if(n == 3){ // 벽이 3개 세워졌을때
//        check++;
        BFS();
        ans = max(ans, space - cnt);
        
        for(int i=0;i<10;i++){
            fill(vis[i], vis[i] + 10, 0);
        }
//        for(int i=1;i<=N;i++){
//            for(int j=1;j<=M;j++){
//                cout<<board[i][j]<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<space - cnt - 3<<endl;
        cnt = 0;
        return;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(board[i][j] == 0 && changed[i][j] == false){
                board[i][j] = 1; // 벽으로 변경
                changed[i][j] = true;
                wall(n+1); // 다음 벽 탐색
                board[i][j] = 0; // 벽을 다시 빈칸으로 변경
                changed[i][j] = false;
            }
        }
    }
}

int main(){
    FAST;
    input();
    wall(0);
    cout<<ans-3;
//    cout<<check;
}

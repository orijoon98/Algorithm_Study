//1520 시간초과 코드
//#include<bits/stdc++.h>
//using namespace std;
//#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//
//int board[501][501];
//int dp[501][501]; // 각 시작점에서 종점까지 갈 수 있는지 확인
//int dpv[501][501]; // dp용 visit
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//
//int main() {
//    FAST;
//    int m, n;
//    int count = 1; // 정답
//    cin>>m>>n;
//    queue<pair<int, int>> S; // dp용 queue
//    queue<pair<int, int>> Q; // 1에서 시작하는 queue
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            cin>>board[i][j];
//        }
//    }
//    //각 시작점 별로 종점까지 도달 할 수 있는지 체크
//    dp[m][n] = 1;
//    for(int i=1;i<=m;i++){
//        for(int j=1;j<=n;j++){
//            dpv[i][j] = 1;
//            S.push({i,j});
//            while(!S.empty()){
//                auto cur = S.front(); S.pop();
//                for(int dir=0;dir<4;dir++){
//                    int nx = cur.first + dx[dir];
//                    int ny = cur.second + dy[dir];
//                    if(nx<1 || ny<1 || nx>m || ny>n) continue;
//                    if(dpv[nx][ny] == 1) continue;
//                    if(board[nx][ny] >= board[cur.first][cur.second]) continue;
//                    if(nx == m && ny == n) dp[i][j] = 1;
//                    dpv[nx][ny] = 1;
//                    S.push({nx,ny});
//                }
//            }
//            for(int i=1;i<=m;i++) fill(dpv[i],dpv[i]+n+1,0);
//        }
//    }
//    //1에서 시작
//    Q.push({1,1});
//    while(!Q.empty()){
//        auto cur = Q.front(); Q.pop();
//        int cnt = 0; // 길이 갈라지는 횟수 확인
//        for(int dir=0;dir<4;dir++){
//            int nx = cur.first + dx[dir];
//            int ny = cur.second + dy[dir];
//            if(nx<1 || ny<1 || nx>m || ny>n) continue;
//            if(board[nx][ny] >= board[cur.first][cur.second]) continue;
//            if(dp[nx][ny] == 0) continue;
//            Q.push({nx,ny});
//            cnt++;
//            if(cnt >= 2) count++;
//        }
//    }
//
//
//    cout<<count<<'\n';
//
//}
//

#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int dp[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;

int DFS(int x, int y){
    if(x == 1 && y == 1) return 1;
    
    if(dp[x][y] == -1){
        dp[x][y] = 0; // 방문처리
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 1 && nx <= m && ny >= 1 && ny <= n){
                if(board[x][y] < board[nx][ny])
                    dp[x][y] += DFS(nx, ny);
            }
        }
    }
    return dp[x][y];
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout<<DFS(m, n);
}

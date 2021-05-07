#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[301][301];
int dist[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(){
    FAST;
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<301;i++){
            fill(board[i], board[i]+301, 0);
            fill(dist[i], dist[i]+301, -1);
        }
        int size, start_a, start_b, target_a, target_b;
        cin>>size>>start_a>>start_b>>target_a>>target_b;
        queue<pair<int,int>> Q;
        dist[start_a][start_b] = 0;
        Q.push({start_a,start_b});
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(cur.first == target_a && cur.second == target_b){
                cout<<dist[cur.first][cur.second]<<'\n';
                break;
            }
            for(int dir=0;dir<8;dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<0 || nx>=size || ny<0 || ny>=size) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
        }
    }
}

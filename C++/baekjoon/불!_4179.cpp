#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

string maze[1000];
int dist[1000][1000];
int distJ[1000][1000];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    FAST;
    cin>>n>>m;
    queue<pair<int,int>> Q;
    for(int i=0;i<n;i++){
        cin>>maze[i];
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'F') Q.push({i,j});
            if(maze[i][j] == '.' || maze[i][j] == 'J' || maze[i][j] == '#') dist[i][j] = -1;
        }
    }
    while(!Q.empty()){ // 불에 대한 DFS
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maze[i][j] == 'J') Q.push({i,j});
            if(maze[i][j] == '.' || maze[i][j] == 'F' || maze[i][j] == '#') distJ[i][j] = -1;
        }
    }
    while(!Q.empty()){ // J에 대한 DFS
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) {
                cout<<distJ[cur.first][cur.second] + 1;
                return 0;
            }
            if(distJ[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1 && dist[nx][ny] <= distJ[cur.first][cur.second] + 1) continue;
            distJ[nx][ny] = distJ[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout<<"IMPOSSIBLE";
}

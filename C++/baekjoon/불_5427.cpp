#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[1001][1001];
int distf[1001][1001];
int dists[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    FAST;
    int n;
    int w, h;
    cin>>n;
    queue<pair<int, int>> Qf;
    queue<pair<int, int>> Qs;
    while(n--){
        cin>>w>>h;
        for(int i=1;i<=h;i++){
            string s;
            cin>>s;
            for(int j=1;j<=w;j++){
                board[i][j] = s[j-1];
                distf[i][j] = -1;
                dists[i][j] = -1;
                if(board[i][j] == '*'){
                    distf[i][j] = 0;
                    Qf.push({i,j});
                }
                if(board[i][j] == '@'){
                    dists[i][j] = 0;
                    Qs.push({i,j});
                }
            }
        }
        //불에 대한 BFS
        while(!Qf.empty()){
            auto cur = Qf.front(); Qf.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<1 || ny<1 || nx>h || ny>w) continue;
                if(board[nx][ny] == '#') continue;
                if(distf[nx][ny] >= 0) continue;
                distf[nx][ny] = distf[cur.first][cur.second] + 1;
                Qf.push({nx,ny});
            }
        }
        //상근에 대한 BFS
        while(!Qs.empty()){
            auto cur = Qs.front(); Qs.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx<1 || ny<1 || nx>h || ny>w) continue;
                if(board[nx][ny] == '#') continue;
                if(dists[nx][ny] >= 0) continue;
                if(distf[nx][ny] != -1 && distf[nx][ny] <= dists[cur.first][cur.second] + 1) continue;
                dists[nx][ny] = dists[cur.first][cur.second] + 1;
                Qs.push({nx,ny});
            }
        }
        int mx = 10000000;
        for(int i=1;i<=h;i++){
            if(dists[i][1] >= 0) mx = min(mx, dists[i][1]);
            if(dists[i][w] >= 0) mx = min(mx, dists[i][w]);
        }
        for(int j=1;j<=w;j++){
            if(dists[1][j] >= 0) mx = min(mx, dists[1][j]);
            if(dists[h][j] >= 0) mx = min(mx, dists[h][j]);
        }
        if(mx == 10000000) cout<<"IMPOSSIBLE"<<'\n';
        else cout<<mx+1<<'\n';
    }
}


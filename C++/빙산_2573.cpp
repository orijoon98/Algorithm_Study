#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int ice[301][301];
vector<pair<int, int>> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

void year(){
    v.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ice[i][j] != 0) v.push_back({i,j}); //빙산의 인덱스 벡터에 추가
        }
    }
    int copy[301][301];
    memcpy(copy, ice, sizeof(ice));
    for(auto i: v){
        int cnt = 0;
        for(int dir=0;dir<4;dir++){
            int nx = i.first + dx[dir];
            int ny = i.second + dy[dir];
            if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if(ice[i.first][i.second] > 0 && ice[nx][ny] == 0) cnt++;
        }
        int cur = ice[i.first][i.second] - cnt;
        copy[i.first][i.second] = (cur > 0) ? cur : 0;
    }
    memcpy(ice, copy, sizeof(copy));
    v.clear();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ice[i][j] != 0) v.push_back({i,j}); //빙산의 인덱스 벡터에 추가
        }
    }
}

int dfs(){ // 빙산의 개수
    int ans = 0;
    queue<pair<int,int>> q;
    int visit[301][301];
    for(int i=1;i<=300;i++) fill(visit[i], visit[i] + 301, 0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ice[i][j] > 0 && visit[i][j] == 0){
                visit[i][j] = 1;
                q.push({i,j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
                        if(ice[nx][ny] == 0 || visit[nx][ny] == 1) continue;
                        visit[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    FAST;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ice[i][j];
        }
    }
    int cnt = 0;
    while(true){
        year();
        cnt++;
        if(dfs() > 1){
            cout<<cnt<<'\n';
            return 0;
        }
        if(v.empty()) break;
    }
    cout<<0<<'\n';
}

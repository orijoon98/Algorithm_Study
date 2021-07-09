#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 987654321

int T, N;
int board[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dis[101][101];

void BFS(){
    for(int i=0;i<101;i++) fill(dis[i], dis[i]+101, -1);
    queue<pair<int,int>> q;
    q.push({1,1});
    dis[1][1] = board[1][1];
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(dis[nx][ny] >= 0){
                if(dis[nx][ny] > dis[cur.first][cur.second] + board[nx][ny]) {
                    dis[nx][ny] = dis[cur.first][cur.second] + board[nx][ny];
                    q.push({nx,ny});
                }
                continue;
            }
            dis[nx][ny] = dis[cur.first][cur.second] + board[nx][ny];
            q.push({nx,ny});
        }
    }
}

void Print(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

void Solution(){
    cin>>T;
    for(int c=1;c<=T;c++){
        cin>>N;
        for(int i=1;i<=N;i++){
            string str;
            cin>>str;
            for(int j=0;j<N;j++){
                board[i][j+1] = str[j] - 48;
            }
        }
        BFS();
        //Print();
        cout<<"#"<<c<<" "<<dis[N][N]<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution();
}

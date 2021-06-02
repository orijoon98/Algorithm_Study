#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int N, L, R;
int board[52][52];
bool vis[52][52];
int cnt = 0;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag = false;

void debug(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

bool fit(int number){
    if(number >= L && number <= R) return true;
    else return false;
}

void input(){
    cin>>N>>L>>R;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }
}

void BFS(){
    flag = false;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(vis[i][j] != 1){
                q.push({i,j});
                vis[i][j] = 1;
                v.push_back({i,j});
                int sum = board[i][j];
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                        if(vis[nx][ny] == 1) continue;
                        if(!fit(abs(board[nx][ny] - board[cur.first][cur.second]))) continue;
                        vis[nx][ny] = 1;
                        sum += board[nx][ny];
                        v.push_back({nx,ny});
                        q.push({nx,ny});
                    }
                }
                int chg = sum / v.size();
                if(v.size() > 1){
                    flag = true;
                    for(auto cur: v){
                        int nx = cur.first;
                        int ny = cur.second;
                        board[nx][ny] = chg;
                    }
//                    debug();
                }
                v.clear();
            }
        }
    }
    if(!flag) return;
    cnt++;
    for(int i=0;i<52;i++) fill(vis[i], vis[i] + 52, false);
    if(flag) BFS();
}

int main(){
    FAST;
    input();
    BFS();
    cout<<cnt;
}

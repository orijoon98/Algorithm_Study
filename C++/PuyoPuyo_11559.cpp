#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

char board[12][6];
bool vis[12][6];
int cnt = 0;
bool changed = false;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void debug(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
}

void input(){
    for(int i=0;i<12;i++){
        for(int j=0;j<6;j++){
            cin>>board[i][j];
        }
    }
}

void gravity(){
    for(int j=0;j<6;j++){ // 열 별로 확인
        int space = 0;
        for(int i=11;i>=0;i--){
            if(board[i][j] == '.') space++; // 내릴 칸수
            else {
                if(space != 0){
                    board[i+space][j] = board[i][j];
                    board[i][j] = '.';
                }
            }
        }
    }
}

void score(){
    for(int i=11;i>=0;i--){
        for(int j=0;j<6;j++){
            if(board[i][j] != '.'){
                q.push({i,j});
                vis[i][j] = 1;
                char color = board[i][j];
                int move = 0;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    v.push_back({cur.first,cur.second});
                    move++;
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        char color2 = board[nx][ny];
                        if(nx < 0 || ny < 0 || nx > 11 || ny > 5) continue;
                        if(vis[nx][ny] || color != color2) continue;
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }
                }
                if(move >= 4){
                    for(auto cur: v){
                        board[cur.first][cur.second] = '.';
                    }
                    changed = true;
                }
                v.clear();
                for(int i=0;i<12;i++) fill(vis[i], vis[i] + 6, false);
            }
        }
    }
    if(changed){ // 연쇄가 일어났으면 중력 작용하고 다시 확인
        cnt++;
        gravity();
        changed = false;
        score();
    }
}

int main(){
    FAST;
    input();
    score();
    cout<<cnt;
}

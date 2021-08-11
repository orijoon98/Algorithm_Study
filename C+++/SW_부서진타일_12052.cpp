#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T, N, M;
char board[50][50];

int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 1, 0};


void Track(int x, int y, char c){
    if(x == N && y == M) return;
    if(c == '.'){
        if(x+1 == N && y+1 == M) return Track(x+1, y+1, '\0');
        else if(y+1 < M) return Track(x, y+1, board[x][y+1]);
        else return Track(x+1, 0, board[x+1][0]);
    }
    for(int cur=0;cur<4;cur++){
        int nx = x + dx[cur];
        int ny = y + dy[cur];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M){
            for(int i=cur-1;i>=0;i--){
                int before_nx = x + dx[i];
                int before_ny = y + dy[i];
                board[before_nx][before_ny] = '#';
            }
            if(x+1 == N && y+1 == M) return Track(x+1, y+1, '\0');
            else if(y+1 < M) return Track(x, y+1, board[x][y+1]);
            else return Track(x+1, 0, board[x+1][0]);
        }
        if(board[nx][ny] == '#') board[nx][ny] = '.';
        else{
            for(int i=cur-1;i>=0;i--){
                int before_nx = x + dx[i];
                int before_ny = y + dy[i];
                board[before_nx][before_ny] = '#';
            }
            if(x+1 == N && y+1 == M) return Track(x+1, y+1, '\0');
            else if(y+1 < M) return Track(x, y+1, board[x][y+1]);
            else return Track(x+1, 0, board[x+1][0]);
        }
    }
    if(x+1 == N && y+1 == M) return Track(x+1, y+1, '\0');
    else if(y+1 < M) return Track(x, y+1, board[x][y+1]);
    else return Track(x+1, 0, board[x+1][0]);
}

void Solution(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N>>M;
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                cin>>board[x][y];
            }
        }
        Track(0, 0, board[0][0]);
        bool flag = true;
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                if(board[x][y] == '#') {
                    flag = false;
                    cout<<"#"<<i<<" NO"<<endl;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<"#"<<i<<" YES"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Solution();
}

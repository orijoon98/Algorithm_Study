#include <bits/stdc++.h>
#define MAX 501
#define endl '\n'
using namespace std;

int N, Ans;
int MAP[MAX][MAX];
int DP[MAX][MAX]; // i, j 번째 칸에서 시작해서 움직일 수 있는 최대 칸 수
int Visit[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Input(){
    cin>>N;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            cin>>MAP[i][j];
}

int DFS(int x, int y){
    if(DP[x][y] != 0) return DP[x][y];
    DP[x][y] = 1;
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
        if(MAP[x][y] < MAP[nx][ny]){
            DP[x][y] = max(DP[x][y], DFS(nx, ny) + 1);
        }
    }
    return DP[x][y];
}

void Solution(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            Ans = max(Ans, DFS(i,j));
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         cout<<DP[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<Ans<<endl;
}

void Solve(){
    Input();
    Solution();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solve();

    return 0;
}
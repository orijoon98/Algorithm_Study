#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[101][101];
int vis[101];

int main(){
    FAST;
    int computer;
    cin>>computer;
    int n;
    cin>>n;
    while(n--){
        int a, b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = 1;
    }
    queue<int> Q;
    vis[1] = 1;
    Q.push(1);
    int cnt = -1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cnt++;
        for(int i=1;i<=computer;i++){
            if(board[cur][i] != 1) continue;
            if(vis[i] == 1) continue;
            vis[i] = 1;
            Q.push(i);
        }
    }
    cout<<cnt<<'\n';
}

#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

int board[1002][1002];
int vis[1002];

int main(){
    FAST;
    int n, m;
    cin>>n>>m;
    while(m--){
        int a, b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = 1;
    }
    queue<int> Q;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(vis[i] != 1){
            vis[i] = 1;
            Q.push(i);
            cnt++;
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                for(int j=1;j<=n;j++){
                    if(board[cur][j] != 1) continue;
                    if(vis[j] == 1) continue;
                    vis[j] = 1;
                    Q.push(j);
                }
            }
        }
    }
    cout<<cnt<<'\n';
}
